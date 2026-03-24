#include "ui.h"

Font mainFont;

int DrawNavButton(Rectangle rec, const char *label, int isActive, float *hoverAnim) {
    Vector2 mouse = GetMousePosition();
    int over = CheckCollisionPointRec(mouse, rec);
    int clicked = over && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    float target = (over || isActive) ? 1.0f : 0.0f;
    *hoverAnim += (target - *hoverAnim) * 0.15f;

    Color bg = isActive ? ACCENT_DIM : (over ? PANEL_HOVER : PANEL_BG);
    DrawRectangleRounded(rec, 0.08f, 6, bg);

    if (isActive) {
        DrawRectangleRounded(
            (Rectangle){ rec.x, rec.y + 8, 3, rec.height - 16 },
            1.0f, 4, ACCENT
        );
    }

    Color textCol = isActive ? TEXT_PRIMARY : (over ? TEXT_PRIMARY : TEXT_SECONDARY);
    DrawTextEx(mainFont, label, (Vector2){ (float)(rec.x + 16), (float)(rec.y + (rec.height - 16) / 2) }, 16, 1, textCol);

    return clicked;
}

void DrawInputField(Rectangle rec, const char *buffer, const char *placeholder, int isFocused) {
    DrawRectangleRounded(rec, 0.1f, 6, INPUT_BG);
    
    Color borderCol = isFocused ? INPUT_FOCUS : INPUT_BORDER;
    DrawRectangleRoundedLines(rec, 0.1f, 6, borderCol);

    float textY = rec.y + (rec.height - FONT_SIZE_SM) / 2;

    if (buffer[0] == '\0' && !isFocused) {
        DrawTextEx(mainFont, placeholder, (Vector2){ (float)(rec.x + 16), (float)textY }, (float)FONT_SIZE_SM, 1, TEXT_MUTED);
    } else {
        DrawTextEx(mainFont, buffer, (Vector2){ (float)(rec.x + 16), (float)textY }, (float)FONT_SIZE_SM, 1, TEXT_PRIMARY);
    }

    if (isFocused && ((int)(GetTime() * 2.5f) % 2 == 0)) {
        Vector2 textW = MeasureTextEx(mainFont, buffer, (float)FONT_SIZE_SM, 1);
        DrawRectangle((int)(rec.x + 16 + textW.x + 2), (int)(rec.y + 14), 2, (int)(rec.height - 28), ACCENT);
    }
}

void DrawResultCard(const char *label, const char *value, float y, Color accentColor) {
    Rectangle card = { CONTENT_X, y, CONTENT_W, 72 };

    DrawRectangleRounded(card, 0.1f, 8, PANEL_BG);
    DrawRectangleRoundedLines(card, 0.1f, 8, INPUT_BORDER);

    DrawRectangleRounded(
        (Rectangle){ card.x, card.y + 12, 3, card.height - 24 },
        1.0f, 4, accentColor
    );

    DrawTextEx(mainFont, label, (Vector2){ (float)(card.x + 20), (float)(card.y + 14) }, (float)FONT_SIZE_XS, 1, TEXT_SECONDARY);
    DrawTextEx(mainFont, value, (Vector2){ (float)(card.x + 20), (float)(card.y + 36) }, (float)FONT_SIZE_MD, 1, accentColor);
}

void DrawPercentageBar(float y, float width, double percent) {
    Rectangle outer = { CONTENT_X, y, width, 28 };
    DrawRectangleRounded(outer, 0.3f, 6, PANEL_BG);

    Color barColor;
    if (percent >= 80.0) barColor = GREEN_OK;
    else if (percent >= 50.0) barColor = ORANGE_WARN;
    else barColor = RED_ERR;

    float fillW = (width - 4) * (float)(percent / 100.0);
    if (fillW < 4) fillW = 4;
    Rectangle fill = { CONTENT_X + 2, y + 2, fillW, 24 };
    DrawRectangleRounded(fill, 0.3f, 6, barColor);

    const char *pctText = TextFormat("%.1f%%", percent);
    Vector2 tw = MeasureTextEx(mainFont, pctText, (float)FONT_SIZE_XS, 1);
    float textX = CONTENT_X + width / 2 - tw.x / 2;
    DrawTextEx(mainFont, pctText, (Vector2){ (float)textX, (float)(y + 7) }, (float)FONT_SIZE_XS, 1, TEXT_PRIMARY);
}

void HandleTextInput(char *buffer, int *count, int maxLen) {
    int key = GetCharPressed();
    while (key > 0) {
        if ((key >= 32) && (key <= 125) && (*count < maxLen - 1)) {
            buffer[*count] = (char)key;
            (*count)++;
            buffer[*count] = '\0';
        }
        key = GetCharPressed();
    }
    if (IsKeyPressed(KEY_BACKSPACE) && *count > 0) {
        (*count)--;
        buffer[*count] = '\0';
    }
    if (IsKeyDown(KEY_BACKSPACE) && IsKeyPressedRepeat(KEY_BACKSPACE) && *count > 0) {
        (*count)--;
        buffer[*count] = '\0';
    }
}

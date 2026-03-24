#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include "string_utils.h"
#include "math_utils.h"
#include "ui.h"

int main(void) {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(WIN_W, WIN_H, "MyCLib - C Libraries");
    SetTargetFPS(60);

    mainFont = LoadFontEx("resources/font.ttf", 96, 0, 0);
    SetTextureFilter(mainFont.texture, TEXTURE_FILTER_BILINEAR);

    Screen currentScreen = SCREEN_STRLEN;

    char input1[MAX_INPUT] = "";
    char input2[MAX_INPUT] = "";
    char input3[MAX_INPUT] = "";
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int activeField = 1;

    float navHover[SCREEN_COUNT] = {0};

    const char *navLabels[SCREEN_COUNT] = {
        "strlen",
        "tolower",
        "toupper",
        "strcmp",
        "strcmp %",
        "min",
    };

    const char *sectionLabels[] = { "STRING UTILS", "MATH UTILS" };
    int sectionStarts[] = { 0, 5 };

    while (!WindowShouldClose()) {

        if (activeField == 1) {
            HandleTextInput(input1, &count1, MAX_INPUT);
        } else if (activeField == 2) {
            HandleTextInput(input2, &count2, MAX_INPUT);
        } else {
            HandleTextInput(input3, &count3, MAX_INPUT);
        }

        if (IsKeyPressed(KEY_TAB)) {
            activeField = (activeField + 1) % 3;
            if (activeField == 0) activeField = 1;
        }

        BeginDrawing();
        ClearBackground(BG_DARK);

        DrawRectangle(0, 0, SIDEBAR_W, WIN_H, BG_SIDEBAR);
        DrawRectangle(SIDEBAR_W - 1, 0, 1, WIN_H, DIVIDER);

        DrawTextEx(mainFont, "MyCLib", (Vector2){ 20, 20 }, 22, 1, TEXT_PRIMARY);
        DrawTextEx(mainFont, "C Libraries", (Vector2){ 20, 46 }, 12, 1, TEXT_SECONDARY);
        DrawRectangle(20, 70, SIDEBAR_W - 40, 1, DIVIDER);

        int baseY = 90;
        for (int s = 0; s < 2; s++) {
            DrawTextEx(mainFont, sectionLabels[s], (Vector2){ 20, baseY }, 10, 1, TEXT_MUTED);
            baseY += 18;

            int start = sectionStarts[s];
            int end = (s == 0) ? 5 : SCREEN_COUNT;

            for (int i = start; i < end; i++) {
                Rectangle btn = { 10, baseY, SIDEBAR_W - 20, BTN_H };
                if (DrawNavButton(btn, navLabels[i], currentScreen == i, &navHover[i])) {
                    if (currentScreen != i) {
                        currentScreen = i;
                        input1[0] = '\0'; count1 = 0;
                        input2[0] = '\0'; count2 = 0;
                        input3[0] = '\0'; count3 = 0;
                        activeField = 1;
                    }
                }
                baseY += BTN_H + 4;
            }
            baseY += 12;
        }

        DrawRectangle(20, WIN_H - 50, SIDEBAR_W - 40, 1, DIVIDER);
        DrawTextEx(mainFont, "C99 + raylib", (Vector2){ 20, (float)(WIN_H - 36) }, 11, 1, TEXT_MUTED);

        switch (currentScreen) {

            case SCREEN_STRLEN: {
                DrawTextEx(mainFont, "my_strlen", (Vector2){ (float)CONTENT_X, 24 }, FONT_SIZE_LG, 1, TEXT_PRIMARY);
                DrawTextEx(mainFont, "Calculate the length of a string", (Vector2){ (float)CONTENT_X, 60 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                DrawRectangle(CONTENT_X, 82, 60, 3, ACCENT);

                DrawTextEx(mainFont, "Input", (Vector2){ (float)CONTENT_X, 100 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                Rectangle field = { CONTENT_X, 118, CONTENT_W, INPUT_H };
                DrawInputField(field, input1, "Type something...", activeField == 1);

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
                    CheckCollisionPointRec(GetMousePosition(), field)) {
                    activeField = 1;
                }

                int len = my_strlen(input1);
                DrawResultCard("Length", TextFormat("%d characters", len), 200, ACCENT);

                float barY = 300;
                DrawTextEx(mainFont, "Character count", (Vector2){ (float)CONTENT_X, (float)barY }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                barY += 20;

                Rectangle barOuter = { CONTENT_X, barY, CONTENT_W, 20 };
                DrawRectangleRounded(barOuter, 0.4f, 6, PANEL_BG);

                float fillPct = (float)len / (MAX_INPUT - 1);
                if (fillPct > 1.0f) fillPct = 1.0f;
                float fillW = (CONTENT_W - 4) * fillPct;
                if (fillW < 2) fillW = 2;
                Rectangle barFill = { CONTENT_X + 2, barY + 2, fillW, 16 };
                DrawRectangleRounded(barFill, 0.4f, 6, ACCENT);

                DrawTextEx(mainFont, TextFormat("%d / %d", len, MAX_INPUT - 1),
                         (Vector2){ (float)CONTENT_X, (float)(barY + 28) }, FONT_SIZE_XS, 1, TEXT_MUTED);
                break;
            }

            case SCREEN_TOLOWER: {
                DrawTextEx(mainFont, "my_tolower", (Vector2){ (float)CONTENT_X, 24 }, FONT_SIZE_LG, 1, TEXT_PRIMARY);
                DrawTextEx(mainFont, "Convert text to lowercase", (Vector2){ (float)CONTENT_X, 60 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                DrawRectangle(CONTENT_X, 82, 60, 3, GREEN_OK);

                DrawTextEx(mainFont, "Input", (Vector2){ (float)CONTENT_X, 100 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                Rectangle field = { CONTENT_X, 118, CONTENT_W, INPUT_H };
                DrawInputField(field, input1, "TYPE SOMETHING HERE...", activeField == 1);

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
                    CheckCollisionPointRec(GetMousePosition(), field)) {
                    activeField = 1;
                }

                char *result = my_tolower(input1);
                const char *display = (result != NULL) ? result : "";
                DrawResultCard("Result", display, 200, GREEN_OK);
                if (result) free(result);
                break;
            }

            case SCREEN_TOUPPER: {
                DrawTextEx(mainFont, "my_toupper", (Vector2){ (float)CONTENT_X, 24 }, FONT_SIZE_LG, 1, TEXT_PRIMARY);
                DrawTextEx(mainFont, "Convert text to UPPERCASE", (Vector2){ (float)CONTENT_X, 60 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                DrawRectangle(CONTENT_X, 82, 60, 3, ACCENT);

                DrawTextEx(mainFont, "Input", (Vector2){ (float)CONTENT_X, 100 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                Rectangle field = { CONTENT_X, 118, CONTENT_W, INPUT_H };
                DrawInputField(field, input1, "type something here...", activeField == 1);

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
                    CheckCollisionPointRec(GetMousePosition(), field)) {
                    activeField = 1;
                }

                char *result = my_toupper(input1);
                const char *display = (result != NULL) ? result : "";
                DrawResultCard("Result", display, 200, ACCENT);
                if (result) free(result);
                break;
            }

            case SCREEN_STRCMP: {
                DrawTextEx(mainFont, "my_strcmp", (Vector2){ (float)CONTENT_X, 24 }, FONT_SIZE_LG, 1, TEXT_PRIMARY);
                DrawTextEx(mainFont, "Compare two strings lexicographically", (Vector2){ (float)CONTENT_X, 60 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                DrawRectangle(CONTENT_X, 82, 60, 3, ACCENT);

                DrawTextEx(mainFont, "String 1", (Vector2){ (float)CONTENT_X, 100 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                Rectangle field1 = { CONTENT_X, 118, CONTENT_W, INPUT_H };
                DrawInputField(field1, input1, "First string...", activeField == 1);

                DrawTextEx(mainFont, "String 2", (Vector2){ (float)CONTENT_X, 188 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                Rectangle field2 = { CONTENT_X, 206, CONTENT_W, INPUT_H };
                DrawInputField(field2, input2, "Second string...", activeField == 2);

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    if (CheckCollisionPointRec(GetMousePosition(), field1)) activeField = 1;
                    if (CheckCollisionPointRec(GetMousePosition(), field2)) activeField = 2;
                }

                int cmp = my_strcmp(input1, input2);
                const char *cmpText;
                Color resColor;
                if (cmp == 0) {
                    cmpText = "EQUAL  (return: 0)";
                    resColor = GREEN_OK;
                } else if (cmp < 0) {
                    cmpText = "String 1 < String 2";
                    resColor = ORANGE_WARN;
                } else {
                    cmpText = "String 1 > String 2";
                    resColor = RED_ERR;
                }

                DrawResultCard("Comparison", cmpText, 288, resColor);
                break;
            }

            case SCREEN_STRCMPPCT: {
                DrawTextEx(mainFont, "my_strcmp_percent", (Vector2){ (float)CONTENT_X, 24 }, FONT_SIZE_LG, 1, TEXT_PRIMARY);
                DrawTextEx(mainFont, "Similarity using Levenshtein distance", (Vector2){ (float)CONTENT_X, 60 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                DrawRectangle(CONTENT_X, 82, 60, 3, ACCENT);

                DrawTextEx(mainFont, "String 1", (Vector2){ (float)CONTENT_X, 100 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                Rectangle field1 = { CONTENT_X, 118, CONTENT_W, INPUT_H };
                DrawInputField(field1, input1, "First string...", activeField == 1);

                DrawTextEx(mainFont, "String 2", (Vector2){ (float)CONTENT_X, 188 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                Rectangle field2 = { CONTENT_X, 206, CONTENT_W, INPUT_H };
                DrawInputField(field2, input2, "Second string...", activeField == 2);

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    if (CheckCollisionPointRec(GetMousePosition(), field1)) activeField = 1;
                    if (CheckCollisionPointRec(GetMousePosition(), field2)) activeField = 2;
                }

                double pct = 0.0;
                if (input1[0] != '\0' || input2[0] != '\0') {
                    pct = my_strcmp_percent(input1, input2);
                }

                DrawResultCard("Similarity",
                               TextFormat("%.1f%% match", pct), 288,
                               pct >= 80.0 ? GREEN_OK : (pct >= 50.0 ? ORANGE_WARN : RED_ERR));

                DrawPercentageBar(388, CONTENT_W, pct);

                int l1 = my_strlen(input1);
                int l2 = my_strlen(input2);
                int maxL = l1 > l2 ? l1 : l2;
                int dist = (maxL == 0) ? 0 : (int)((1.0 - pct / 100.0) * maxL + 0.5);

                DrawTextEx(mainFont, TextFormat("Edit distance: %d operations", dist),
                         (Vector2){ (float)CONTENT_X, 434 }, FONT_SIZE_XS, 1, TEXT_MUTED);
                break;
            }

            case SCREEN_MIN: {
                DrawTextEx(mainFont, "my_min", (Vector2){ (float)CONTENT_X, 24 }, FONT_SIZE_LG, 1, TEXT_PRIMARY);
                DrawTextEx(mainFont, "Returns the minimum of three integers", (Vector2){ (float)CONTENT_X, 60 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);
                DrawRectangle(CONTENT_X, 82, 60, 3, ORANGE_WARN);

                DrawTextEx(mainFont, "Enter three integers", (Vector2){ (float)CONTENT_X, 100 }, FONT_SIZE_XS, 1, TEXT_SECONDARY);

                int fieldW = (CONTENT_W - 24) / 3;
                Rectangle field1 = { CONTENT_X, 118, fieldW, INPUT_H };
                Rectangle field2 = { CONTENT_X + fieldW + 12, 118, fieldW, INPUT_H };
                Rectangle field3 = { CONTENT_X + 2 * (fieldW + 12), 118, fieldW, INPUT_H };

                DrawInputField(field1, input1, "a", activeField == 1);
                DrawInputField(field2, input2, "b", activeField == 2);
                DrawInputField(field3, input3, "c", activeField == 3);

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    if (CheckCollisionPointRec(GetMousePosition(), field1)) activeField = 1;
                    if (CheckCollisionPointRec(GetMousePosition(), field2)) activeField = 2;
                    if (CheckCollisionPointRec(GetMousePosition(), field3)) activeField = 3;
                }

                int a = atoi(input1);
                int b = atoi(input2);
                int c = atoi(input3);
                int result = min(a, b, c);

                DrawResultCard("Minimum", TextFormat("%d", result), 200, ORANGE_WARN);

                DrawTextEx(mainFont, "Formula: min(a, b, c) - returns the smallest of three values",
                         (Vector2){ (float)CONTENT_X, 300 }, FONT_SIZE_XS, 1, TEXT_MUTED);
                break;
            }

            default:
                break;
        }

        EndDrawing();
    }

    UnloadFont(mainFont);
    CloseWindow();
    return 0;
}

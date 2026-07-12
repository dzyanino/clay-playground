#define CLAY_IMPLEMENTATION // ok so first the clay implementation macro

#include "lib/clay.h" // then import clay just after
#include "lib/renderers/raylib.c" // NOLINT(bugprone-suspicious-include)

#include "include/theme/colors.h"
#include "include/theme/fonts.h"

#include "include/pages/welcome/welcome.h"

void HandleClayErrors(Clay_ErrorData error_data)
{
	printf("[ERROR BRO]===> %s\n", error_data.errorText.chars);
	exit(1);
} // make an error handler to give it to clay initializer so that i can debug (or catch probably) errors better

/*
 *
 * MAIN FUNCTION
 */
int main(void)
{
	Clay_Raylib_Initialize(800, 600, "Clay with Raylib", FLAG_WINDOW_RESIZABLE); // initialize raylib window

	SetTargetFPS(60);

	uint64_t clay_required_memory = Clay_MinMemorySize(); // get the required memory to launch clay

	Clay_Arena clay_memory = (Clay_Arena) {
		.memory = malloc(clay_required_memory),
		.capacity = clay_required_memory,
	}; // make an arena with the memory size

	Clay_Initialize(
	  clay_memory,
		(Clay_Dimensions) { .width = (float) GetScreenWidth(), .height = (float) GetScreenHeight() },
		(Clay_ErrorHandler) { HandleClayErrors }
	); // initialize clay with the arena (memory), and its default dimensions
		// and the error handler (catcher)

	Font fonts[FONT_COUNT];
	fonts[0] = LoadFontEx("assets/fonts/BricolageGrotesque-Regular.ttf", 48, 0, 0);
	fonts[1] = LoadFontEx("assets/fonts/BricolageGrotesque-SemiBold.ttf", 48, 0, 0);
	fonts[2] = LoadFontEx("assets/fonts/BricolageGrotesque-Bold.ttf", 48, 0, 0);
	fonts[3] = LoadFontEx("assets/fonts/Fraunces-Bold.ttf", 48, 0, 0);
	fonts[4] = LoadFontEx("assets/fonts/Fraunces-Italic.ttf", 48, 0, 0);
	fonts[5] = LoadFontEx("assets/fonts/SpaceMono-Regular.ttf", 48, 0, 0);
	fonts[6] = LoadFontEx("assets/fonts/SpaceMono-Bold.ttf", 48, 0, 0);
	fonts[7] = LoadFontEx("assets/fonts/SpaceMono-Italic.ttf", 48, 0, 0);

	for (int i = 0; i < FONT_COUNT; i++)
	{
		SetTextureFilter(fonts[i].texture, TEXTURE_FILTER_BILINEAR);
	} // fix graininess in text when put below the fontSize of the LoadFont function's fontSize parameter

	Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);
	// call this function to tell clay how to properly size the fonts
	// so that it knows how to layout CLAY_TEXT for example
	// here i'll just use the provided callback function from raylib's renderer

	while (!WindowShouldClose())
	{ // main loop

		float delta_time = GetFrameTime();

		Clay_SetLayoutDimensions((Clay_Dimensions) {
		  .width = (float) GetScreenWidth(),
			.height = (float) GetScreenHeight(),
		}); // update the layout every frame to match the current window's dimensions

		Vector2 mouse_position = GetMousePosition();
		Vector2 scroll_delta = GetMouseWheelMoveV();
		Clay_SetPointerState((Clay_Vector2) { mouse_position.x, mouse_position.y }, IsMouseButtonDown(MOUSE_LEFT_BUTTON));
		Clay_UpdateScrollContainers(
		  true,
			(Clay_Vector2) { scroll_delta.x, scroll_delta.y },
			delta_time
		); // mouse position and click tracking

		SetMouseCursor(MOUSE_CURSOR_DEFAULT); // to prevent overriding in the button component cursor change

		Clay_BeginLayout();
		// the layouts (ui hierarchy) should be put between here and `Clay_EndLayout`

		CLAY(
        CLAY_ID("main-container"),
        {
          .layout = {
            .sizing = {
              .width = CLAY_SIZING_GROW(0),
              .height = CLAY_SIZING_GROW(0)
            },
            .padding = CLAY_PADDING_ALL(16),
            .childGap = 16,
          },
          .backgroundColor = theme_colors[M_COLOR_DARK_BACKGROUND]
        }
      )
		{
			PageWelcome();
		}

		Clay_RenderCommandArray render_commands = Clay_EndLayout(delta_time);
		// those layouts will then be computed as raw render commands that any renderer should be able to understand
		// as long as there is a translation layer for them

		BeginDrawing();
		ClearBackground(GREEN); // another background behind clay to see the space between clay's ui and raylib's
		Clay_Raylib_Render(render_commands, fonts); // then render the commands with raylib, with the corresponding font
		EndDrawing();
	}
}

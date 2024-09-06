#include <stdio.h>
#include <stdint.h>

#define MAX_LEDS 10  // Define the maximum number of LEDs in the group

// Structure to represent individual LED settings
struct LEDSettings {
    uint8_t state;       // 1 = ON, 0 = OFF
    uint8_t brightness;  // Brightness level from 0 to 255
    uint32_t color;      // Color value in RGB format (0xRRGGBB)
};

// Structure to represent a group of LEDs
struct LEDGroup {
    struct LEDSettings leds[MAX_LEDS];  // Array to hold multiple LEDs
    uint8_t groupState;          // 1 = all ON, 0 = all OFF
    uint8_t groupBrightness;     // Group-wide brightness adjustment
    uint32_t groupColor;         // Group-wide color (in RGB format 0xRRGGBB)
};

// Function to initialize the LED group with default values
void initLEDGroup(struct LEDGroup *group) {
    // Initialize all LEDs in the group
    for (int i = 0; i < MAX_LEDS; i++) {
        group->leds[i].state = 0;         // Turn off all LEDs
        group->leds[i].brightness = 0;    // Set brightness to minimum
        group->leds[i].color = 0x000000;  // Set color to black (off)
    }
    group->groupState = 0;                // Group is off
    group->groupBrightness = 0;           // Group brightness to minimum
    group->groupColor = 0x000000;         // Group color to black (off)
}

// Function to update both individual LEDs and group settings
void updateLEDGroupSettings(struct LEDGroup *group, uint8_t groupState, uint8_t groupBrightness,
                            uint32_t groupColor, uint8_t ledIndex,
                            uint8_t state,uint8_t brightness, uint32_t color) {

    // Update group-wide settings 
    group->groupState = groupState;
    group->groupBrightness = groupBrightness;
    group->groupColor = groupColor;

    
    //Apply group-wide settings to all the individual LEDs only if the groupState indicates all LEDs should be ON
    if (groupState == 1) {
        for (int i = 0; i < MAX_LEDS; i++) {
            group->leds[i].state = groupState;
            group->leds[i].brightness = groupBrightness;
            group->leds[i].color = groupColor;
        }
    }

    // Now, update individual LED settings for the specified index
    if (ledIndex < MAX_LEDS) {
        group->leds[ledIndex].state = state;
        group->leds[ledIndex].brightness = brightness;
        group->leds[ledIndex].color = color;
        printf("\nUpdating individual LED %d: State=%d, Brightness=%d, Color=0x%06X\n",
               ledIndex, group->leds[ledIndex].state, group->leds[ledIndex].brightness, group->leds[ledIndex].color);
    } else {
        // Edge case if index of mentioned LED is out of range.
        printf("\nIndex is out of range. Please enter a valid LED index.\n");
    }



}

// Function to display the current status of the LED group
void displayLEDGroupStatus(struct LEDGroup *group) {
    // Print individual LED settings for each LED in the group
    printf("________Individual LED Statuses_________\n");
    for (int i = 0; i < MAX_LEDS; i++) {
        printf("LED %d - State: %s, Brightness: %u, Color: 0x%06X\n",
                i, (group->leds[i].state == 1) ? "ON" : "OFF",group->leds[i].brightness, group->leds[i].color);
    }
    printf("\n");

    // Print group-wide settings
    printf("__________Group Status__________\n");
    printf("Group State: %s\n", (group->groupState == 1) ? "All ON" : "All OFF");
    printf("Group Brightness Adjustment: %u\n", group->groupBrightness);
    printf("Group Color: 0x%06X\n", group->groupColor);
}

int main() {

    //define your LEDGroup with a name.
    struct LEDGroup myLEDGroup;

    // Initialize the LED group with default values
    initLEDGroup(&myLEDGroup);

    // Display default LED group status
    printf("Default LED Group Status:\n");
    displayLEDGroupStatus(&myLEDGroup);

    // Update the LED group with new settings for the individual LEDs
    //define your own LEDGroup settings and individual LED settings by using the below format
    /*updateLEDGroupSettings(&declared_LEDGroupName, uint8_t groupState, uint8_t groupBrightness,uint32_t groupColor, 
                                uint8_t ledIndex,uint8_t state,uint8_t brightness, uint32_t color)*/

    //Test case 1
    updateLEDGroupSettings(&myLEDGroup, 1, 150, 0xFF00FF, 0, 1, 200, 0xFF0000); // LED 0: ON, brightness 200, color red
    // Display updated LED group status
    printf("\nUpdated LED Group Status:\n");
    displayLEDGroupStatus(&myLEDGroup);

    //Test case 2
    updateLEDGroupSettings(&myLEDGroup, 1, 150, 0xFF00FF, 1, 1, 180, 0x00FF00); // LED 1: ON, brightness 180, color green
    
    // Display updated LED group status
    printf("\nUpdated LED Group Status:\n");
    displayLEDGroupStatus(&myLEDGroup);

    //Test case 3 out of range led index
    updateLEDGroupSettings(&myLEDGroup, 1, 150, 0xFF00FF, 20, 1, 150, 0x0000FF); // LED 20: ON, brightness 150, color blue. Testing edge case.
    // Display updated LED group status
    printf("\nUpdated LED Group Status:\n");
    displayLEDGroupStatus(&myLEDGroup);

    return 0;
}

//____________INSTRUCTIONS TO TEST THE ABOVE CODE_______________
/* 
1. define your LEDGroup with a name.
    struct LEDGroup myLEDGroup;

2. Initialize the LED group with default values
    initLEDGroup(&myLEDGroup);

3. Update the LED group with new settings for the individual LEDs and group settings.

    -define your own LEDGroup settings and individual LED settings by using the below format:
    updateLEDGroupSettings(&myLEDGroup, uint8_t groupState,
                                uint8_t groupBrightness,uint32_t groupColor, 
                                uint8_t ledIndex,uint8_t state,uint8_t brightness, uint32_t color);

    example usage: updateLEDGroupSettings(&myLEDGroup, 1, 150, 0xFF00FF, 1, 1, 180, 0x00FF00);

4. Display updated LED group status
    printf("\nUpdated LED Group Status:\n");
    displayLEDGroupStatus(&myLEDGroup);
*/


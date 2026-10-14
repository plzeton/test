#include <furi.h>
#include <furi_hal.h>
#include <furi_hal_usb_hid.h>

// Główna funkcja aplikacji
int32_t usb_keyboard_app_main(void* p) {
    UNUSED(p);

    // 1. Przełącz port USB w tryb emulacji klawiatury (HID)
    furi_hal_usb_set_config(&furi_hal_usb_hid, NULL);
    furi_delay_ms(1000); // Daj czas systemowi Windows na wykrycie urządzenia

    // 2. Wyślij sekwencję klawiszy (np. skrót Win + R)
    // furi_hal_hid_kb_press i release obsługują kody skanowania klawiatury (Keycodes)
    furi_hal_hid_kb_press(KEY_MOD_LEFT_GUI);
    furi_hal_hid_kb_press(HID_KEYBOARD_R);
    furi_delay_ms(50);
    furi_hal_hid_kb_release(KEY_MOD_LEFT_GUI);
    furi_hal_hid_kb_release(HID_KEYBOARD_R);
    
    furi_delay_ms(500);

    // Przywróć domyślny tryb USB Flippera przed wyjściem
    furi_hal_usb_set_config(&furi_hal_usb_cdc, NULL);

    return 0;
}

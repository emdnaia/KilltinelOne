#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    HKEY hKey;
    const char* keyPath = "SOFTWARE\\Sentinel Labs\\Agent";
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyPath, 0, KEY_WRITE | KEY_WOW64_64KEY, &hKey) == ERROR_SUCCESS) {
        const char* externalIdValue = "SAPLA";
        RegSetValueEx(hKey, "externalId", 0, REG_SZ, (BYTE*)externalIdValue, strlen(externalIdValue));
        const char* installationInitiatorValue = "SAPLAAA>";
        RegSetValueEx(hKey, "installationInitiator", 0, REG_SZ, (BYTE*)installationInitiatorValue, strlen(installationInitiatorValue));
        const char* skipMemCheckValue = "true";
        RegSetValueEx(hKey, "skipMemCheck", 0, REG_SZ, (BYTE*)skipMemCheckValue, strlen(skipMemCheckValue));
        RegCloseKey(hKey);
    }
    else {
        printf("cannot edit registry try with admininistrative credentials\n");
    }

    return 0;
}

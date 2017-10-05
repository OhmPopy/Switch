#if defined(_WIN32)

#include <windows.h>
#include "../../include/Switch/Undef.hpp"

#include <cstdlib>

#include "CoreApi.hpp"

int32 __OS::CoreApi::Registry::CloseKey(intptr key) {
  return RegCloseKey((HKEY)key);
}

int32 __OS::CoreApi::Registry::CreateSubKey(intptr rootKey, const string& subKey, intptr& key) {
  DWORD disposition = 0;
  HKEY newKey = NULL;
  return RegCreateKeyEx((HKEY)rootKey, subKey.w_str().c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS | KEY_CREATE_SUB_KEY, NULL, (PHKEY)&key, &disposition);
}

int32 __OS::CoreApi::Registry::DeleteTree(intptr hKey, const string& subkeyName) {
  return RegDeleteTree((HKEY)hKey, subkeyName.w_str().c_str());
}

int32  __OS::CoreApi::Registry::DeleteSubKey(intptr hKey, const string& subkeyName) {
  return RegDeleteKeyEx((HKEY)hKey, subkeyName.w_str().c_str(), KEY_WOW64_64KEY, 0);
}

int32 __OS::CoreApi::Registry::DeleteValue(intptr hKey, const string& subkeyName) {
  return RegDeleteValueW((HKEY)hKey, subkeyName.w_str().c_str());
}

int32  __OS::CoreApi::Registry::EnumKey(intptr key, int32 index, string& keyName) {
  wchar_t name[256];
  DWORD size = 255;
  if (RegEnumKeyEx((HKEY)key, index, name, &size, NULL, NULL, NULL, NULL) != ERROR_SUCCESS)
    return -1;
  keyName = name;
  return 0;
}

int32  __OS::CoreApi::Registry::EnumValues(intptr key, int32 index, string& keyName, Microsoft::Win32::RegistryValueKind& kind) {
  int32 keyLength = 16383;
  std::wstring kn(keyLength, '\0');
  if (RegEnumValue((HKEY)key, index, (LPWSTR)kn.c_str(), (LPDWORD)&keyLength, NULL, (LPDWORD)&kind, NULL, NULL) != ERROR_SUCCESS)
    return -1;
  keyName = kn;
  return 0;
}

int32 __OS::CoreApi::Registry::Flush(intptr key) {
  return RegFlushKey((HKEY)key);
}

string __OS::CoreApi::Registry::GetDefaultString() {
  return "";
}

int32 __OS::CoreApi::Registry::GetHandleBaseKey(Microsoft::Win32::RegistryHive reghive, intptr& key) {
  switch (reghive) {
  case Microsoft::Win32::RegistryHive::ClassesRoot: key = (intptr)HKEY_CLASSES_ROOT; break;
  case Microsoft::Win32::RegistryHive::CurrentConfig: key = (intptr)HKEY_CURRENT_CONFIG; break;
  case Microsoft::Win32::RegistryHive::CurrentUser: key = (intptr)HKEY_CURRENT_USER; break;
  case Microsoft::Win32::RegistryHive::DynData: key = (intptr)HKEY_DYN_DATA; break;
  case Microsoft::Win32::RegistryHive::LocalMachine: key = (intptr)HKEY_LOCAL_MACHINE; break;
  case Microsoft::Win32::RegistryHive::PerformanceData: key = (intptr)HKEY_PERFORMANCE_DATA; break;
  case Microsoft::Win32::RegistryHive::Users: key = (intptr)HKEY_USERS; break;
  default: key = 0; break;
  }
  return 0;
}

int32 __OS::CoreApi::Registry::GetValue(intptr hkey, const string& subKey, Microsoft::Win32::RegistryValueKind& type, System::Array<byte>& data) {
  int32 size = 0;
  if (RegQueryValueEx((HKEY)hkey, subKey.w_str().c_str(), 0, (DWORD*)&type, NULL, (LPDWORD)&size) != ERROR_SUCCESS)
    return -1;
  
  System::Array<>::Resize(data, size);
  return RegQueryValueEx((HKEY)hkey, subKey.w_str().c_str(), 0, (DWORD*)&type, (LPBYTE)data.Data(), (LPDWORD)&size);
}

int32 __OS::CoreApi::Registry::NumberOfSubKey(intptr key) {
  LPSTR className = null;
  DWORD classNameSize = MAX_PATH, subKey = 0, maxSubKey, maxClass, value, maxValue, maxValueData, securityDescriptor;
  FILETIME ftLastWriteTime;
  
  if (RegQueryInfoKeyA((HKEY)key, className, &classNameSize, null, &subKey, &maxSubKey, &maxClass, &value, &maxValue, &maxValueData, &securityDescriptor, &ftLastWriteTime) == ERROR_SUCCESS)
    return subKey;
  return -1;
}

int32 __OS::CoreApi::Registry::NumberOfValue(intptr key) {
  LPSTR className = null;
  DWORD classNameSize = MAX_PATH, subKey = 0, maxSubKey, maxClass, value, maxValue, maxValueData, securityDescriptor;
  FILETIME ftLastWriteTime;
  
  if (RegQueryInfoKeyA((HKEY)key, className, &classNameSize, null, &subKey, &maxSubKey, &maxClass, &value, &maxValue, &maxValueData, &securityDescriptor, &ftLastWriteTime) == ERROR_SUCCESS)
    return value;
  return -1;
}

int32 __OS::CoreApi::Registry::OpenSubKey(intptr rootKey, const string& subKey, intptr& key) {
  return RegOpenKeyEx((HKEY)rootKey, subKey.w_str().c_str(), 0, KEY_ALL_ACCESS | KEY_CREATE_SUB_KEY, (PHKEY)&key);
}

int32  __OS::CoreApi::Registry::QueryInfoKey(intptr hkey, int32& subKey, int32& value) {
  LPSTR className = null;
  DWORD classNameSize = MAX_PATH, subKeyResultQuery = 0, maxSubKey, maxClass, valueResultQuery, maxValue, maxValueData, securityDescriptor;
  FILETIME ftLastWriteTime;
  
  if (RegQueryInfoKeyA((HKEY)hkey, className, &classNameSize, null, &subKeyResultQuery, &maxSubKey, &maxClass, &valueResultQuery, &maxValue, &maxValueData, &securityDescriptor, &ftLastWriteTime) != ERROR_SUCCESS)
    return -1;

  subKey = subKeyResultQuery;
  value = valueResultQuery;
  return 0;
}

int32 __OS::CoreApi::Registry::SetValue(intptr key, const string& keyName, Microsoft::Win32::RegistryValueKind type, const byte* data, int32 length) {
  return RegSetValueEx((HKEY)key, keyName.w_str().c_str(), 0, (DWORD)type, (const BYTE*)data, length);
}

#endif
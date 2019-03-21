#ifndef recommendpic_h
#define recommendpic_h

#ifdef recommendpic_EXPORTS  
#define recommendpic_EXPORTS __declspec(dllexport)  
#else  
#define recommendpic_EXPORTS __declspec(dllimport)  
#endif

#ifdef __cplusplus
extern "C" {
#endif
    int __stdcall queryId(int id, char* tfl, char* pfl, char* lines);
#ifdef __cplusplus
}
#endif

#endif
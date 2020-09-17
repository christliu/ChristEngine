
// define opengl function here
// typedef BOOL (WINAPI   * PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
// typedef HGLRC (WINAPI  * PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int *attribList);
// typedef BOOL (WINAPI   * PFNWGLSWAPINTERVALEXTPROC) (int interval);
// typedef void (APIENTRY * PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
// typedef void (APIENTRY * PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
// typedef void (APIENTRY * PFNGLBINDVERTEXARRAYPROC) (GLuint array);
// typedef void (APIENTRY * PFNGLBUFFERDATAPROC) (GLenum target, ptrdiff_t size, const GLvoid *data, GLenum usage);
// typedef void (APIENTRY * PFNGLCOMPILESHADERPROC) (GLuint shader);
// typedef GLuint(APIENTRY * PFNGLCREATEPROGRAMPROC) (void);
// typedef GLuint(APIENTRY * PFNGLCREATESHADERPROC) (GLenum type);
// typedef void (APIENTRY * PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint *buffers);
// typedef void (APIENTRY * PFNGLDELETEPROGRAMPROC) (GLuint program);
// typedef void (APIENTRY * PFNGLDELETESHADERPROC) (GLuint shader);
// typedef void (APIENTRY * PFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint *arrays);
// typedef void (APIENTRY * PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
// typedef void (APIENTRY * PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
// typedef void (APIENTRY * PFNGLGENBUFFERSPROC) (GLsizei n, GLuint *buffers);
// typedef void (APIENTRY * PFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint *arrays);
// typedef GLint(APIENTRY * PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const char *name);
// typedef void (APIENTRY * PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei *length, char *infoLog);
// typedef void (APIENTRY * PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint *params);
// typedef void (APIENTRY * PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, char *infoLog);
// typedef void (APIENTRY * PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint *params);
// typedef void (APIENTRY * PFNGLLINKPROGRAMPROC) (GLuint program);
// typedef void (APIENTRY * PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const char* *string, const GLint *length);
// typedef void (APIENTRY * PFNGLUSEPROGRAMPROC) (GLuint program);
// typedef void (APIENTRY * PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
// typedef void (APIENTRY * PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const char *name);
// typedef GLint(APIENTRY * PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const char *name);
// typedef void (APIENTRY * PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
// typedef void (APIENTRY * PFNGLACTIVETEXTUREPROC) (GLenum texture);
// typedef void (APIENTRY * PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
// typedef void (APIENTRY * PFNGLGENERATEMIPMAPPROC) (GLenum target);
// typedef void (APIENTRY * PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
// typedef void (APIENTRY * PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat *value);
// typedef void (APIENTRY * PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat *value);

// PFNGLATTACHSHADERPROC glAttachShader;
// PFNGLBINDBUFFERPROC glBindBuffer;
// PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
// PFNGLBUFFERDATAPROC glBufferData;
// PFNGLCOMPILESHADERPROC glCompileShader;
// PFNGLCREATEPROGRAMPROC glCreateProgram;
// PFNGLCREATESHADERPROC glCreateShader;
// PFNGLDELETEBUFFERSPROC glDeleteBuffers;
// PFNGLDELETEPROGRAMPROC glDeleteProgram;
// PFNGLDELETESHADERPROC glDeleteShader;
// PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
// PFNGLDETACHSHADERPROC glDetachShader;
// PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
// PFNGLGENBUFFERSPROC glGenBuffers;
// PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
// PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
// PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
// PFNGLGETPROGRAMIVPROC glGetProgramiv;
// PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
// PFNGLGETSHADERIVPROC glGetShaderiv;
// PFNGLLINKPROGRAMPROC glLinkProgram;
// PFNGLSHADERSOURCEPROC glShaderSource;
// PFNGLUSEPROGRAMPROC glUseProgram;
// PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
// PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
// PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
// PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
// PFNGLACTIVETEXTUREPROC glActiveTexture;
// PFNGLUNIFORM1IPROC glUniform1i;
// PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
// PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
// PFNGLUNIFORM3FVPROC glUniform3fv;
// PFNGLUNIFORM4FVPROC glUniform4fv;

HGLRC wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int *attribList) { return __wglCreateContextAttribsARB(hDC, hShareContext, attribList); }
// wglChoosePixelFormatARB
BOOL wglChoosePixelFormatARB(HDC hdc, const int* piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats) { return __wglChoosePixelFormatARB(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats); }
// wglSwapIntervalEXT
BOOL wglSwapIntervalEXT(int interval) { return __wglSwapIntervalEXT(interval); }
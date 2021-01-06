# ChristEngine

This is note of my idea when I wrote ChristEngine. Maybe I will erase them all  after several days.

## FistPart

* Directory Tree
* CMake
* OpenGL without any third library such as glut。

> Messiah更新之后取消了RHI的设计，初步思考是为了作framegraph的时候更灵活处理各个device的特性。

OpenGL在windows平台上，都是通过动态链接OpenGL32.dll的，而OpenGL32.dll只支持OpenGL1.1, 于是要想在windows上使用新版opengl的功能，都要用扩展访问，即调用wglGetProcAddress获取地址。



## Dev Schedule

* opengl device .
* graphics manager render loop every frame in main thread.
* primitives && model render with camera.
* scene manager with scene.
* skeleton animation.
* shader with light and shadow.
* pbr relearn.
* dx11.
* dx12
* vulkan.
* multithread rendering.

Change my dev schedule.

* use premake instead of cmake which is much easier.
* let my engine export dll and program import the dll.
* log system
* event system

## Event System

event type:

window_resize window_close

keypress keyrelease

mouseclick mousemove



event class

GetType() static GetType



eventdispatcher

dispatch<T>(event& e)

{

e.GetType() in T::GetType()

}

## Link Error

dllexport class in headerfile.

if no include of this header file in any source file, this will lead a link error.



## Git svn


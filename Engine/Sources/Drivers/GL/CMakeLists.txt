AUX_SOURCE_DIRECTORY(./Private GL_SRCS)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/Sources/Graphics/Public)
INCLUDE_DIRECTORIES(C:/Users/Christliu/gitrepo/ChristEngine/Engine/Sources/Graphics/Public)

INCLUDE_DIRECTORIES(Public)
message("ok")
message(${PROJECT_SOURCE_DIR}/Sources/Graphics/Public)

ADD_LIBRARY(GL STATIC ${GL_SRCS})

TARGET_LINK_LIBRARIES(GL Graphics)


//
//  textureloader.h
//  Tetris_Final
//
//  Created by Данила Дудин on 24.05.2020.
//  Copyright © 2020 Данила Дудин. All rights reserved.
//

#ifndef textureloader_h
#define textureloader_h

/// The returned char* must be deleted by the calling function.
///
/// Example usage:
///    unsigned int width, height;
///    unsigned char * data = loadBMPRaw(imagepath, width, height);
///    // Create one OpenGL texture
///    GLuint textureID;
///    glGenTextures(1, &textureID);
///
///    // "Bind" the newly created texture : all future texture functions will modify this texture
///    glBindTexture(GL_TEXTURE_2D, textureID);
///
///    // Give the image to OpenGL
///    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
///
///    // Poor filtering, or ...
///    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
///    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
///
///    // ... nice trilinear filtering.
///    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
///    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
///    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
///    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
///    glGenerateMipmap(GL_TEXTURE_2D);
/// delete[] data;
unsigned char * loadBMPRaw(const char * imagepath, unsigned int& outWidth, unsigned int& outHeight, bool flipY = true);

#endif

#endif /* textureloader_h */

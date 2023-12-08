#ifndef  IMAGE_HPP
#define  IMAGE_HPP

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

// Function to load a BMP file
GLubyte* LoadBMP(const char *fileName, int *width, int *height) {
    FILE *file;
    unsigned char header[54];
    unsigned int dataPos;
    unsigned int imageSize;
    unsigned int width_, height_;
    unsigned char *data;

    file = fopen(fileName, "rb");
    if (!file) {
        printf("Image could not be opened\n");
        return NULL;
    }

    if (fread(header, 1, 54, file) != 54) {
        printf("Not a correct BMP file\n");
        return NULL;
    }

    if (header[0] != 'B' || header[1] != 'M') {
        printf("Not a correct BMP file\n");
        return NULL;
    }

    dataPos = *(int*)&(header[0x0A]);
    imageSize = *(int*)&(header[0x22]);
    width_ = *(int*)&(header[0x12]);
    height_ = *(int*)&(header[0x16]);

    if (imageSize == 0) imageSize = width_ * height_ * 3;
    if (dataPos == 0) dataPos = 54;

    data = (unsigned char *)malloc(imageSize);
    fread(data, 1, imageSize, file);
    fclose(file);

    *width = width_;
    *height = height_;

    return data;
}

GLuint loadTexture(const char *filename) {
    int width, height;
    GLuint textureID;
    GLubyte *data = LoadBMP(filename, &width, &height);

    if (data) {
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
        free(data);
    } else {
        printf("Failed to load BMP\n");
        return 0;
    }

    return textureID;
}

GLuint textures[9]; // Array to hold texture IDs
int currentTexture; // Index to keep track of the current texture

#endif

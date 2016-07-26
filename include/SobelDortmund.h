/**
* \file Tools/ImageProcessing/Sobel.h
* Declares functions for calculating the sobel operator on a given image using SSE.
*
* @author <A href=mailto:fabian.rensen@tu-dortmund.de>Fabian Rensen</A>
*/
#pragma once

#include "SIMD.h"
#include "Vector2D.h"

class SobelDortmund
{
 public:
  enum Direction
  {
    Uni,
    Horizontal,
    Vertical
  };

  /**
   * @brief Returns the sobel image for a YUV422 image using every Y value. Corner coordinates are interpreted as image coordinates, which
   * means that if you have a full size image of 1280 by 960, the full size rectangle is defined by (0,0) to (1279, 959) !
   * Start and end corners can be either top left and bottom right or top right and bottom left in any order.
   * @param [in] YUVImage The YUV422 image on which the sobel is calculated.
   * @param [in] startX Start corner in image coordinates, i.e. starting at 0 and ending at width - 1.
   * @param [in] startY Start corner in image coordinates, i.e. starting at 0 and ending at width - 1.
   * @param [in] endX End corner in image coordinates, i.e. starting at 0 and ending at width - 1.
   * @param [in] endY End corner in image coordinates, i.e. starting at 0 and ending at width - 1.
   * @param [in] width Width of the image.
   * @param [in] height Height of the image.
   * @param [in] dir If you want the normal sobel in both horizontal and vertical directions or only one of them. Both (=Uni) is the standard value.
   * @param [in] returnFullArray If you want a full size result even if the defined rectangle is smaller than the full image. Everything outside the
   * rectangle is filled black. Otherwise the result is the size of the rectangle.
   * @return The sobel result.
   */
  static const stdVector2D<unsigned char> sobelSSEAnyYUVImageFull(const unsigned char* YUVImage, int startX, int startY, int endX, int endY, int width, int height,
                                                            Direction dir = Uni, bool returnFullArray = true);

  /**
   * @brief Overloaded function taking the robots upper image instead of any image. A rectangle may be defined.
   * @see sobelSSEAnyYUVImageFull
   */
  static const stdVector2D<unsigned char> sobelSSEImageUpperFull(const unsigned char* imageUpper, int startX, int startY, int endX, int endY, Direction dir = Uni,
                                                           bool returnFullArray = true)
  {
    return sobelSSEAnyYUVImageFull(imageUpper, startX, startY, endX, endY, IMAGE_UPPER_FULL_WIDTH, IMAGE_UPPER_FULL_HEIGHT, dir, returnFullArray);
  }

  /**
   * @brief Overloaded function taking the robots lower image instead of any image. A rectangle may be defined.
   * @see sobelSSEAnyYUVImageFull
   */
  static const stdVector2D<unsigned char> sobelSSEImageLowerFull(const unsigned char* imageLower, int startX, int startY, int endX, int endY, Direction dir = Uni,
                                                           bool returnFullArray = true)
  {
    return sobelSSEAnyYUVImageFull(imageLower, startX, startY, endX, endY, IMAGE_LOWER_FULL_WIDTH, IMAGE_LOWER_FULL_HEIGHT, dir, returnFullArray);
  }

  /**
   * @brief Overloaded function taking the robots upper image instead of any image and calculating the sobel operator on the whole image (not a
   * rectangle).
   * @see sobelSSEAnyYUVImageFull
   */
  static const stdVector2D<unsigned char> sobelSSEImageUpperFull(const unsigned char* imageUpper, Direction dir = Uni)
  {    
    int startX = 0;
    int startY = 0;
    int endX = IMAGE_UPPER_FULL_WIDTH - 1;
    int endY = IMAGE_UPPER_FULL_HEIGHT - 1;

    return sobelSSEAnyYUVImageFull(imageUpper, startX, startY, endX, endY, IMAGE_UPPER_FULL_WIDTH, IMAGE_UPPER_FULL_HEIGHT, dir, true);
  }

  /**
   * @brief Overloaded function taking the robots lower image instead of any image and calculating the sobel operator on the whole image (not a
   * rectangle).
   * @see sobelSSEAnyYUVImageFull
   */
  static const stdVector2D<unsigned char> sobelSSEImageLowerFull(const unsigned char* imageLower, Direction dir = Uni)
  {    
    int startX = 0;
    int startY = 0;
    int endX = IMAGE_LOWER_FULL_WIDTH - 1;
    int endY = IMAGE_LOWER_FULL_HEIGHT - 1;

    return sobelSSEAnyYUVImageFull(imageLower, startX, startY, endX, endY, IMAGE_LOWER_FULL_WIDTH, IMAGE_LOWER_FULL_HEIGHT, dir, true);
  }

  /**
   * @brief Returns the sobel image for a YUV422 image using every second Y value and every second row. Corner coordinates are interpreted as image
   * coordinates, which
   * means that if you have a quarter size image of 640 by 480, the full size rectangle is defined by (0,0) to (639, 479) !
   * Start and end corners can be either top left and bottom right or top right and bottom left in any order.
   * @param [in] YUVImage The YUV422 image on which the sobel is calculated.
   * @param [in] startX Start corner in image coordinates, i.e. starting at 0 and ending at width - 1.
   * @param [in] startY Start corner in image coordinates, i.e. starting at 0 and ending at width - 1.
   * @param [in] endX End corner in image coordinates, i.e. starting at 0 and ending at width - 1.
   * @param [in] endY End corner in image coordinates, i.e. starting at 0 and ending at width - 1.
   * @param [in] width Width of the quarter image.
   * @param [in] height Height of the quarter image.
   * @param [in] dir If you want the normal sobel in both horizontal and vertical directions or only one of them. Both is standard value.
   * @param [in] returnFullArray If you want a full size result even if the defined rectangle is smaller than the full image. Everything outside the
   * rectangle is filled black. Otherwise the result is the size of the rectangle.
   * @return The sobel result.
   */
  static const stdVector2D<unsigned char> sobelSSEAnyYUVImageQuarter(const unsigned char* YUVImage, int startX, int startY, int endX, int endY, int width, int height,
                                                               Direction dir = Uni, bool returnFullArray = true);

  /**
   * @brief Overloaded function taking the robots upper image instead of any image. A rectangle and a direction may be defined.
   * @see sobelSSEImageUpperQuarter
   */
  static const stdVector2D<unsigned char> sobelSSEImageUpperQuarter(const unsigned char* imageUpper, int startX, int startY, int endX, int endY, Direction dir = Uni,
                                                              bool returnFullArray = true)
  {
    return sobelSSEAnyYUVImageQuarter(imageUpper, startX, startY, endX, endY, IMAGE_UPPER_FULL_WIDTH / 2, IMAGE_UPPER_FULL_HEIGHT / 2, dir, returnFullArray);
  }

  /**
   * @brief Overloaded function taking the robots upper image instead of any image and calculating the sobel operator on the whole image (not a
   * rectangle).
   * @see sobelSSEImageUpperQuarter
   */
  static const stdVector2D<unsigned char> sobelSSEImageUpperQuarter(const unsigned char* imageUpper, Direction dir = Uni)
  {
    int startX = 0;
    int startY = 0;
    int endX = IMAGE_UPPER_FULL_WIDTH / 2 - 1;
    int endY = IMAGE_UPPER_FULL_HEIGHT / 2 - 1;

    return sobelSSEAnyYUVImageQuarter(imageUpper, startX, startY, endX, endY, IMAGE_UPPER_FULL_WIDTH / 2, IMAGE_UPPER_FULL_HEIGHT / 2, dir, true);
  }


  /**
   * @brief Overloaded function taking the robots lower image instead of any image. A rectangle and a direction may be defined.
   * @see sobelSSEImageUpperQuarter
   */
  static const stdVector2D<unsigned char> sobelSSEImageLowerQuarter(const unsigned char* imageLower, int startX, int startY, int endX, int endY, Direction dir = Uni,
                                                              bool returnFullArray = true)
  {
    return sobelSSEAnyYUVImageQuarter(imageLower, startX, startY, endX, endY, IMAGE_LOWER_FULL_WIDTH / 2, IMAGE_LOWER_FULL_HEIGHT / 2, dir, returnFullArray);
  }

  /**
   * @brief Overloaded function taking the robots lower image instead of any image and calculating the sobel operator on the whole image (not a
   * rectangle).
   * @see sobelSSEImageUpperQuarter
   */
  static stdVector2D<unsigned char> sobelSSEImageLowerQuarter(const unsigned char* imageLower, Direction dir = Uni)
  {

    int startX = 0;
    int startY = 0;
    int endX = IMAGE_LOWER_FULL_WIDTH / 2 - 1;
    int endY = IMAGE_LOWER_FULL_HEIGHT / 2 - 1;
    return sobelSSEAnyYUVImageQuarter(imageLower, startX, startY, endX, endY, IMAGE_LOWER_FULL_WIDTH / 2, IMAGE_LOWER_FULL_HEIGHT / 2, dir, true);
  }


 private:
   
  //------------ Edit if you are using other image sizes --------------
  // Constants regarding image sizes
  static const int IMAGE_UPPER_FULL_WIDTH = 1280;
  static const int IMAGE_UPPER_FULL_HEIGHT = 960;
  static const int IMAGE_LOWER_FULL_WIDTH = 640;
  static const int IMAGE_LOWER_FULL_HEIGHT = 480;
  //-------------------------------------------------------------------

  /**
   *
   * @method switchStartEnd
   * @brief Switches two vectors to be always a top left and a bottom right corner. This is a helper function for the sobel functions.
   * @param  start          Vector 1.
   * @param  end            Vector 2.
   */
  static void switchStartEnd(int& startX, int& startY, int& endX, int& endY);
};

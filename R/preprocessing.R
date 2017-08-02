quantization <- function (img){
  grey_img <- EBImage::channel(img, mode = "grey")
  grey_level <- EBImage::equalize(grey_img, levels = 256)
  return(grey_level)
}

quant_binary <- function (img, wi = 50, hi = 50, threshold = 0.05){
  grey_level_img <- quantization(img)
  bin_img <- 1-EBImage::thresh(grey_level_img, w = wi, h = hi, offset = threshold)
  return(bin_img)
}

quant_binary_recon <- function (img, wi = 50, hi = 50, threshold = 0.05, dsize = 19){
  binary <- quant_binary(img, wi = wi, hi = hi, threshold = threshold)
  binary_closed <- EBImage::closing(binary, kern = makeBrush(dsize, shape = "disc"))
  return(binary_closed)
}

make_gradients <- function (img){
  sobel_filterX = matrix(c(1,2,1,0,0,0,-1,-2,-1), nrow = 3, ncol = 3)
  sobel_filterY = matrix(c(1,0,-1,2,0,-2,1,0,-1), nrow = 3, ncol = 3)
  grey_level <- quantization(img)
  XGrad = EBImage::filter2(grey_level, sobel_filterX)
  YGrad = EBImage::filter2(grey_level, sobel_filterY)
  gradient_mag = sqrt(XGrad^2+YGrad^2)
  return(gradient_mag)
}

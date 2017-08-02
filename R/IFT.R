gen_seed_pixels <- function (bin_img, num){
  height <- dim(bin_img)[1]
  width <- dim(bin_img)[2]
  h2 <- height/80
  w2 <- width/80
  print(w2)
  print(h2)
  res_img <- EBImage::resize(bin_img, w = w2, h = h2)
  total_points <- w2*h2
  print(total_points)
  possible_points <- vector(length = 0)
  number_points_added <- 0
  for (i in 1:w2)
  {
    for (j in 1:h2){
      if (bin_img[j, i] == 1){
        current_pixel <- w2*(j-1)+i
        possible_points[number_points_added] <- current_pixel
        number_points_added <- number_points_added + 1
      }
    }
  }
  return(number_points_added)
}

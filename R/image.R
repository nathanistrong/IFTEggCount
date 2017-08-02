pixel <- setRefClass("pixel", fields = list(val = "numeric", Xpos = "numeric", Ypos = "numeric", vec = "vector"))

pixel$methods(
  listForm = function(){
    vec <<- vector(Xpos, Ypos, val)
  }
)

IFTImage <- setRefClass("IFTImage", fields = list(data1 = "matrix", pixels = "list", nrows = "numeric", ncols = "numeric"))

IFTImage$methods(
  initializeImage = function(){
    nrows <<- dim(data1)[1]
    ncols <<- dim(data1)[2]
    listedValues = as.list((t(data1)))
    totalNum = nrows*ncols
    tempList<- listedValues
    for(i in 1:totalNum)
    {
      currentValue <- as.integer(listedValues[i])
      currentYpos <- i %/% 2464
      currentXPos <- i %% 2464
      currentPixel <- pixel(val = currentValue, Xpos = currentXPos, Ypos = currentYpos)
      tempList[i] <- currentPixel$vec
    }
    pixels <<- tempList
  }
)

IFTImage$methods(
  getFirstZero = function(){
    total = length(pixels)
    counti = 0
    for(i in 1:total)
    {
      if(pixels[i] == 0 & counti == 0)
      {
        counti = i
      }
    }
    return(counti)
  }
)

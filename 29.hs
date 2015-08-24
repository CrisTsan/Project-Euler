import Data.List  


list=[ a^b | a<-[2..100],b<-[2..100]]
length (nub list)


 #!/bin/sh
echo  > Rapport 

if [ -f "src/makefile" ];then
 cd src
 make
 cd ..
fi

for video in test/*
do 
      
      echo -e " ------ Rapport pour fichier "$video ".." >> Rapport
      src/./compil < $video >> Rapport
done

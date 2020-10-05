#include <stdlib.h>
#include<stdio.h>
#include <SDL/SDL.h>
#include <ctime>
#include <cmath>
#include <SDL/SDL_ttf.h>
#include <fmod/fmod.h>

int lose(SDL_Rect position1,SDL_Rect position2)
{
           int m=1;
           if(position1.x+48<=position2.x+80 && position1.x+14>=position2.x)
           {
             if(position1.y+12<=position2.y-100 || position1.y+37>=position2.y)
               {
                   m=0;
               }
               else
                 m=2;
           }
           return m;

}


//LA FONCTION MAIN
int main (int argc,char *argv[])
{
  int i=0,j=1,yy=0;
   int u=1;

     FMOD_SYSTEM *system;
     FMOD_SOUND *tir = NULL;
     FMOD_RESULT resultat;
     FMOD_System_Create(&system);
     FMOD_System_Init(system,32,FMOD_INIT_NORMAL, NULL);
     resultat=FMOD_System_CreateSound(system, "eat.wav",FMOD_CREATESAMPLE,0,&tir);
           if (resultat != FMOD_OK)
           {
               fprintf(stderr, "Impossible de lire pan.wav\n");
               exit(EXIT_FAILURE);
            }
while(j=1)
{
     SDL_Surface *ecran=NULL;
     SDL_Surface *image=NULL,*image1[10],*ima2=NULL,*ima=NULL,*text=NULL,*imag=NULL;
     SDL_Rect position,position0;
     position.x = 0;
     position.y = 0;
     SDL_Rect position1;
     position1.x =-440;
     position1.y =0;
      SDL_Rect position2;
     position2.x =50;
     position2.y =90;
     position0.x=50;
     position0.y=30;
     int n;
     srand(time(NULL));
      n=((rand()%200)/10);
     SDL_Rect position3,position4;
     position3.x =400;
     position3.y =n*10+140;
     position4.x =400;
     SDL_Event event;
     int po=1,neg=440,pos=0,pos1=0,pos2=0,neg1=440,neg2=620,test=1,p=1,sco=0,sc=0;
     char ch[3];
     sprintf(ch,"%d",sco);
     pos=position3.y-400;
     position4.y =pos;
     SDL_Rect position5,position6;
     n=((rand()%200)/10);
     position5.x =400;
     position5.y =n*10+140;
     position6.x =400;
     pos1=position5.y-400;
     position6.y =pos1;
     SDL_Rect position7,position8;
     n=((rand()%200)/10);
     position7.x =400;
     position7.y =n*10+140;
     position8.x =400;
     pos2=position7.y-400;
     position8.y =pos2;
     TTF_Font *police = NULL;
     SDL_Color couleurNoire = {0,250,250};

     SDL_Init( SDL_INIT_VIDEO);
     TTF_Init();
     ecran=SDL_SetVideoMode(440,440,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
     SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 250, 250,250));
     ima=SDL_LoadBMP("ima.bmp");
     SDL_BlitSurface(ima, NULL, ecran,&position);
     image=SDL_LoadBMP("image3.bmp");
     SDL_SetColorKey(image,SDL_SRCCOLORKEY, SDL_MapRGB(image->format,0,0,0));
     SDL_BlitSurface(image, NULL,ecran,&position2);
     image1[0]=SDL_LoadBMP("i1.bmp");
    SDL_SetColorKey(image1[0],SDL_SRCCOLORKEY, SDL_MapRGB(image->format,255,242,0));
     SDL_BlitSurface(image1[0], NULL,ecran,&position3);
     image1[1]=SDL_LoadBMP("i2.bmp");
      SDL_SetColorKey(image1[1],SDL_SRCCOLORKEY, SDL_MapRGB(image->format,255,242,0));
     SDL_BlitSurface(image1[1], NULL,ecran,&position4);
      image1[2]=SDL_LoadBMP("i1.bmp");
     SDL_SetColorKey(image1[2],SDL_SRCCOLORKEY, SDL_MapRGB(image->format,255,242,0));
     image1[3]=SDL_LoadBMP("i2.bmp");
     SDL_SetColorKey(image1[3],SDL_SRCCOLORKEY, SDL_MapRGB(image->format,255,242,0));
     image1[4]=SDL_LoadBMP("i1.bmp");
     SDL_SetColorKey(image1[4],SDL_SRCCOLORKEY, SDL_MapRGB(image->format,255,242,0));
     image1[5]=SDL_LoadBMP("i2.bmp");
     SDL_SetColorKey(image1[5],SDL_SRCCOLORKEY, SDL_MapRGB(image->format,255,242,0));
     police = TTF_OpenFont("police.ttf",20);
     text=TTF_RenderText_Blended(police,ch,couleurNoire);
     SDL_BlitSurface(text, NULL, ecran, &position0);
       SDL_Rect los;
       los.x=100;
       los.y=100;
      imag=SDL_LoadBMP("lose.bmp");
     SDL_SetColorKey(imag,SDL_SRCCOLORKEY, SDL_MapRGB(imag->format,255,255,255));
     SDL_Flip(ecran);


     SDL_PollEvent(&event);
            switch(event.type)
           {
             case SDL_QUIT:
             return EXIT_SUCCESS;
             break;
             case SDL_KEYDOWN:

               switch (event.key.keysym.sym)
               {
                   case SDLK_SPACE:
                       i=1;
                 break;
               }
               break ;
           }

 while (i)
{
           yy=1;
  if(neg>=-80)
  {
             position2.y=position2.y+2*p;
    if(po==1)
    {
      neg=neg-10;
      position3.x=neg;
      position4.x=neg;
      SDL_BlitSurface(ima, NULL, ecran,&position);
      SDL_BlitSurface(image1[0], NULL,ecran,&position3);
      position4.y =pos;
      SDL_BlitSurface(image1[1], NULL,ecran,&position4);
      if(neg1>140)
       {
           neg1=neg+200;
           position5.x=neg1;
           position6.x=neg1;
           SDL_BlitSurface(image1[2], NULL,ecran,&position5);
           position6.y =pos1;
           SDL_BlitSurface(image1[3], NULL,ecran,&position6);
           if(neg2>140)
           {
            neg2=neg1+200;
            position7.x=neg2;
            position8.x=neg2;
            SDL_BlitSurface(image1[4], NULL,ecran,&position7);
            position8.y =pos2;
            SDL_BlitSurface(image1[5], NULL,ecran,&position8);
            image=SDL_LoadBMP("image2.bmp");
            SDL_SetColorKey(image,SDL_SRCCOLORKEY, SDL_MapRGB(image->format,0,0,0));
            SDL_BlitSurface(image, NULL,ecran,&position2);
            text=TTF_RenderText_Blended(police,ch,couleurNoire);
            SDL_BlitSurface(text, NULL, ecran, &position0);
            SDL_Flip(ecran);
            }
            else
            {
            neg2=neg2-10;
            position7.x=neg2;
            position8.x=neg2;
            SDL_BlitSurface(image1[4], NULL,ecran,&position7);
            position8.y=pos2;
            SDL_BlitSurface(image1[5], NULL,ecran,&position8);
            image=SDL_LoadBMP("image2.bmp");
            SDL_SetColorKey(image,SDL_SRCCOLORKEY, SDL_MapRGB(image->format,0,0,0));
            SDL_BlitSurface(image, NULL,ecran,&position2);
            text=TTF_RenderText_Blended(police,ch,couleurNoire);
            SDL_BlitSurface(text, NULL, ecran, &position0);
            SDL_Flip(ecran);
            if(neg2==-80)
            {
               neg2=620;
               n=((rand()%200)/10);
               position7.y=n*10+140;
               pos2=position7.y-400;
             }
            }
        }
        else
       {
           neg1=neg1-10;
           position5.x=neg1;
           position6.x=neg1;
           SDL_BlitSurface(image1[2], NULL,ecran,&position5);
           position6.y =pos1;
           SDL_BlitSurface(image1[3], NULL,ecran,&position6);
           if(neg2>140)
           {
             neg2=neg1+200;
             position7.x=neg2;
             position8.x=neg2;
             SDL_BlitSurface(image1[4], NULL,ecran,&position7);
             position8.y =pos2;
             SDL_BlitSurface(image1[5], NULL,ecran,&position8);
             image=SDL_LoadBMP("image2.bmp");
             SDL_SetColorKey(image,SDL_SRCCOLORKEY, SDL_MapRGB(image->format,0,0,0));
             SDL_BlitSurface(image, NULL,ecran,&position2);
             text=TTF_RenderText_Blended(police,ch,couleurNoire);
             SDL_BlitSurface(text, NULL, ecran, &position0);
             SDL_Flip(ecran);
           }
           else
           {
            neg2=neg2-10;
            position7.x=neg2;
            position8.x=neg2;
            SDL_BlitSurface(image1[4], NULL,ecran,&position7);
            position8.y=pos2;
            SDL_BlitSurface(image1[5], NULL,ecran,&position8);
            image=SDL_LoadBMP("image2.bmp");
            SDL_SetColorKey(image,SDL_SRCCOLORKEY, SDL_MapRGB(image->format,0,0,0));
            SDL_BlitSurface(image, NULL,ecran,&position2);
            text=TTF_RenderText_Blended(police,ch,couleurNoire);
            SDL_BlitSurface(text, NULL, ecran, &position0);
            SDL_Flip(ecran);
            if(neg2==-80)
            {
              neg2=620;
              n=((rand()%200)/10);
              position7.y=n*10+140;
              pos2=position7.y-400;
            }
           }
           if(neg1==-80)
           {
             neg1=440;
             n=((rand()%200)/10);
             position5.y=n*10+140;
             pos1=position5.y-400;
           }
       }


       }
           else
           {
            position2.y=position2.y+2*p;
            n=((rand()%200)/10);
            position3.y=n*10+140;
            pos=position3.y-400;
            po=1;
           }
     }
    if(neg<-80)
       {
          //   position2.y=position2.y+10;
            image=SDL_LoadBMP("image2.bmp");
            SDL_SetColorKey(image,SDL_SRCCOLORKEY, SDL_MapRGB(image->format,0,0,0));
            SDL_BlitSurface(image, NULL,ecran,&position2);
          //  SDL_Flip(ecran);
            neg=510;
            po=0;
        }
        p++;
                 //

            SDL_PollEvent(&event);
            switch(event.type)
           {
             case SDL_QUIT:
             return EXIT_SUCCESS;
             break;
             case SDL_KEYDOWN:

               switch (event.key.keysym.sym)
               {
                   case SDLK_SPACE:
                  SDL_BlitSurface(ima, NULL, ecran,&position);
                  if(u==1)
                  {
                  position2.y=position2.y-50;
                  p=1;
//                  FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0,NULL);
                  }
                  u=0;
                    if(neg==510)
                 {
                      position3.x=-90;
                      position4.x=-90;
                 }
                 if(neg<0)
                 {
                      position3.x=neg;
                      position4.x=neg;
                 }
                   if(neg1==440 )
                 {
                      position5.x=440;
                      position6.x=440;
                 }
                 if(neg1<0)
                 {
                      position5.x=neg1;
                      position6.x=neg1;
                 }

                   if(neg2==620 )
                 {
                      position7.x=620;
                      position8.x=620;
                 }
                 if(neg2<0)
                 {
                      position7.x=neg2;
                      position8.x=neg2;
                 }
                 SDL_BlitSurface(image1[0], NULL,ecran,&position3);
                 position4.y =pos;
                 SDL_BlitSurface(image1[1], NULL,ecran,&position4);
                 SDL_BlitSurface(image1[2], NULL,ecran,&position5);
                 position6.y=pos1;
                 SDL_BlitSurface(image1[3], NULL,ecran,&position6);
                 SDL_BlitSurface(image1[4], NULL,ecran,&position7);
                 position8.y=pos2;
                 SDL_BlitSurface(image1[5], NULL,ecran,&position8);
                 image=SDL_LoadBMP("image.bmp");
                 SDL_SetColorKey(image,SDL_SRCCOLORKEY, SDL_MapRGB(image->format,0,0,0));
                 SDL_BlitSurface(image, NULL,ecran,&position2);
                 text=TTF_RenderText_Blended(police,ch,couleurNoire);
                 SDL_BlitSurface(text, NULL, ecran, &position0);
                 SDL_Flip(ecran);
                 break;
               }
            break;
           case SDL_KEYUP :
                u=1;
           break ;
           }
            SDL_Delay(40);
             if(lose(position2,position3)==0 || lose(position2,position5)==0|| lose(position2,position7)==0 || position2.y==440)
             {
               i=0;
             }
                if(lose(position2,position3)==2 || lose(position2,position5)==2|| lose(position2,position7)==2 )
             {
              sco++;
              if(sco%5==0)
              {
                  sc=sco/5;
                 sprintf(ch,"%d",sc);
              }
             }
       }

     if(yy==1)
     {
              /*  los.y=0;
                int nn=0;
                 while(nn<5)
                {*/
                 los.y=100;
                // nn++;
                 SDL_BlitSurface(imag, NULL,ecran,&los);
                  SDL_Flip(ecran);
                 SDL_Delay(60);
              //  }
                SDL_Delay(1000);
     yy=0;
     }

  TTF_CloseFont(police);
}

     TTF_Quit();
     SDL_Quit();
    FMOD_Sound_Release(tir);
     FMOD_System_Close(system);
     FMOD_System_Release(system);
    return EXIT_SUCCESS;
}


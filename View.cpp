#include "View.h"


void View::format()
{
    if (dynamic_cast<Runner*>(obj) != 0)
    {
       QMovie *vid = new QMovie(obj->getImage());
       this->setMovie(vid);
       vid->start();
    }
    else
    {
       this->setPixmap(QPixmap(obj->getImage()));
    }
    this->setGeometry(obj->format());
    this->setScaledContents(true);
}

void View::ReSize()
{
    this->setGeometry(obj->format());
}

void View::Update(QRect* par, int BSS, int SS)
{

    if (dynamic_cast<Background*>(obj) != 0 && !dynamic_cast<Backdrop*>(obj) != 0) //background
    {
        //Scroll logic
        this->move(obj->get_x() - BSS, obj->get_y());
        obj->set_x(obj->get_x() - BSS);

        //reposition logic
        if(obj->get_x() <= -par->width() + BSS)
        {
           this->move(par->width() , obj->get_y());
           obj->set_x(par->width());
        }
    }
    else if(dynamic_cast<Backdrop*>(obj) != 0) //backdrop
    {
        this->move(obj->get_x() - SS, obj->get_y());
        obj->set_x(obj->get_x() - SS);

        if(obj->get_x() <= -par->width() + SS)
        {
           this->move(par->width() , obj->get_y());
           obj->set_x(par->width());
        }
    }
    else if(dynamic_cast<Runner*>(obj) != 0)//runner
    {
        //for (int i = 0; i <
        //    if (obj->)
        //}

        if (main->get_j())
        {
            jump();
        }
        else if (main->get_s())
        {
            slide();
        }

    }
    else if( dynamic_cast<lowob*>(obj) != 0)//lowob
    {
        this->move(obj->get_x() - SS, obj->get_y());
        obj->set_x(obj->get_x() - SS);

         if(obj->get_x() <= -par->width()/ 7 + SS/4)
         {
            this->move(par->width()/ 7* 13 , obj->get_y());
            obj->set_x(par->width()/ 7* 13 );
         }
    }
    else if( dynamic_cast<midob*>(obj) != 0)//lowob
    {
        this->move(obj->get_x() - SS, obj->get_y());
        obj->set_x(obj->get_x() - SS);

         if(obj->get_x() <= -par->width()/ 7 + SS/4)
         {
            this->move(par->width()/ 7* 13 , obj->get_y());
            obj->set_x(par->width()/ 7* 13 );
            obj->setActive(true);
         }
    }



//       if (main->sliding)
//       {
//       dude->setMovie(running);
//       dude->move(dude->x(), 720);
//       }
}

void View::jump()
{
//    if (main->get_j())
//    {
//        QMovie *vid = new QMovie(obj->getImage());
//        this->setMovie(vid);
//        vid->start();
//        this->setMovie(vid);
//    }
    this->move(this->x(), this->y() - jumpSpeed);
    jumpSpeed -= gravity;


    if (this->y() == obj->get_y())
    {
        jumpSpeed = 35;
        this->move(this->x(), this->y());
        main->set_j(false);
    }

}

void View::slide()
{
           if (slideLength == 20) {
            QPixmap slide1(":/stuff/slide1.png");
            this->setPixmap(slide1);
        } else if (slideLength == 19){
            QPixmap slide2(":/stuff/slide2.png");
            this->setPixmap(slide2);
        } else if (slideLength == 18) {
            QPixmap slide3(":/stuff/slide3.png");
            this->setPixmap(slide3);
        } else if (slideLength <= 17 && slideLength >= 4) {
            QPixmap slide4(":/stuff/slide4.png");
            this->setPixmap(slide4);
        } else if (slideLength == 3) {
            QPixmap slide3(":/stuff/slide3.png");
            this->setPixmap(slide3);
        } else if (slideLength == 2) {
            QPixmap slide2(":/stuff/slide2.png");
            this->setPixmap(slide2);
        } else if (slideLength == 1) {
            QPixmap slide1(":/stuff/slide1.png");
            this->setPixmap(slide1);
        } else if (slideLength == 0) {
            slideLength = 21;
            main->set_s(false);
            if (!main->get_s())
            {
                QMovie *vid = new QMovie(obj->getImage());
                this->setMovie(vid);
                vid->start();
                this->setMovie(vid);
                this->move(obj->get_x(), obj->get_y());
                //delete vid;
            }

        }
       slideLength --;
}

bool View::Test(GameModel* stuff)
{
//    if(dynamic_cast<Runner*>(obj) != 0)
//    {
////        if(stuff->Collision(obj))
////        {
////            return true;
////        }
//    }
}

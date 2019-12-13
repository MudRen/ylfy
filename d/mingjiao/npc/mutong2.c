// mutong.c 

#include <ansi.h>

inherit NPC;



void create()

{

    set_name("牧童", ({ "mu tong", "tong"}));

     

      set("long", 

        "他，愁容满面，一脸苦涩之像，仿佛刚刚降临了一场大祸！\n");

            set("gender", "男性");

        set("age", 15);

        set("attitude", "peaceful");

        set("shen_type", 1);

        set("str", 32);

        set("int", 30);

        set("con", 28);

        set("dex", 34);

        

        set("combat_exp", 20);

        set("inquiry", ([

"牛" : "我的牛被人抢了。\n",

"九阳真经" : "你先帮我找到牛，我就给你那本书。\n",

"身份" : "我是张教主的牧童，专门替他放牛！\n",

        ]));

        set("book_count", 1);



        setup();

        carry_object("/clone/cloth/cloth")->wear();


        set("chat_chance", 1);

        set("chat_msg", ({

"牧童低头叹道：这可怎么办？\n",

"牧童低头喃喃道: 回家可怎么交代啊！\n",

        }) ); 

   

}



void init()

{

	object me, ob;


        me = this_object();



      if(present("niu", this_player())     )

        {

                if (me->query("book_count") < 1){

                     write(CYN "你来晚了，牛我已经找到了。\n"NOR);

                return;

                }



        command("say 哇！太谢谢你了，这本书就借给你看几天，不要给张教主知道了哦！\n");

ob = new("/d/mingjiao/obj/jiuyang1");	

                 ob->move(this_player());

                 

                 destruct(present("huang niu", this_player()));

                 me->add("book_count", -1);



                 return;

        }



        return;

}








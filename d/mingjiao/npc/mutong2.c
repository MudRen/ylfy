// mutong.c 

#include <ansi.h>

inherit NPC;



void create()

{

    set_name("��ͯ", ({ "mu tong", "tong"}));

     

      set("long", 

        "�����������棬һ����ɬ֮�񣬷·�ոս�����һ�������\n");

            set("gender", "����");

        set("age", 15);

        set("attitude", "peaceful");

        set("shen_type", 1);

        set("str", 32);

        set("int", 30);

        set("con", 28);

        set("dex", 34);

        

        set("combat_exp", 20);

        set("inquiry", ([

"ţ" : "�ҵ�ţ�������ˡ�\n",

"�����澭" : "���Ȱ����ҵ�ţ���Ҿ͸����Ǳ��顣\n",

"���" : "�����Ž�������ͯ��ר��������ţ��\n",

        ]));

        set("book_count", 1);



        setup();

        carry_object("/clone/cloth/cloth")->wear();


        set("chat_chance", 1);

        set("chat_msg", ({

"��ͯ��ͷ̾���������ô�죿\n",

"��ͯ��ͷ�૵�: �ؼҿ���ô��������\n",

        }) ); 

   

}



void init()

{

	object me, ob;


        me = this_object();



      if(present("niu", this_player())     )

        {

                if (me->query("book_count") < 1){

                     write(CYN "�������ˣ�ţ���Ѿ��ҵ��ˡ�\n"NOR);

                return;

                }



        command("say �ۣ�̫лл���ˣ��Ȿ��ͽ���㿴���죬��Ҫ���Ž���֪����Ŷ��\n");

ob = new("/d/mingjiao/obj/jiuyang1");	

                 ob->move(this_player());

                 

                 destruct(present("huang niu", this_player()));

                 me->add("book_count", -1);



                 return;

        }



        return;

}








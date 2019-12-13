// daoshi.c  ��ɽ��ʿ
#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("��ɽ��ʿ", ({"dao shi"}));
        set("gender", "����");
        set("age", 25);
        set("long",
             "����ȫ��̵Ļ�ɽ��ʿ��ר���ػ�ɽ�š� \n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 17);
        set("int", 14);
        set("con", 17);
        set("dex", 14);

        set("chat_chance", 1);
        set("chat_msg", ({
          "��ɽ��ʿ˵��������ȫ������������̣��ɲ����ý�������С���ˡ���\n",          "��ɽ��ʿ˵������������Ĺǧ����Ҵ�����������Σ�յġ���\n",
       "��ɽ��ʿ˵������Ҫ˵��ȫ��̳������˵��书���ٺ٣����ӿ�����ú�ѽ����\n",
        (: random_move :),
        }));

        set("qi", 450);
        set("max_qi", 450);
        set("jing", 350);
        set("max_jing", 350);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 20);
        
        set("combat_exp", 100000);
        set("score", 3000);
 
        set_skill("force", 90);             // �����ڹ�
        set_skill("tiangang-zhengqi", 90);    //�������
        set_skill("unarmed", 90);           // ����ȭ��
        set_skill("kongming-quan", 90);    //����ȭ 
        set_skill("dodge",90);               // ��������
        set_skill("qixing-huanwei", 80);        //���ǻ�λ
        set_skill("parry",90);             // �����м�
        set_skill("sword", 90);             // ��������
        set_skill("quanzhen-jianfa", 90);        //ȫ�潣��
        set_skill("literate",30);           //����д��  
  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("ȫ���",4, "����");
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
       carry_object("/d/quanzhen/obj/yellowrobe")->wear();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
 void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say(CYN"��ɽ��ʿ�ʵ�����λ" + RANK_D->query_respect(ob)
                                + "������ʦ����\n"NOR);
                        break;
                case 1:
                        say(CYN"��ɽ��ʿ˵������λ" + RANK_D->query_respect(ob)
                                + "��ӭ�㵽ȫ������\n"NOR);
                        break;
        }
}


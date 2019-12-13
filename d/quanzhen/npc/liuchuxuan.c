//liuchuxuan.c ������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("������", ({"liu chuxuan", "liu", "chuxuan"}));
        set("nickname", HIC"������"NOR);
        set("gender", "����");
        set("age", 51);
        set("long",
             "�����ΰ�С����Ŀ����Գ��һ��������ò�����\n"
                "������ȫ�������еġ������ӡ���������\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("chat_chance", 20);
        set("chat_msg", ({
                "������˵�������콫��������˹��Ҳ�������������ǣ��������......����\n",
//               (: random_move :),
        }));

        set("inquiry", ([
                "��԰":"��԰���ƽ������ĵط���ֻ���������ϵĵ��Ӳ����ʸ�ݼ��ƽ̡�\n",
                ]));

        set("qi", 2400);
        set("max_qi", 2400);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 2200);
        set("max_neili", 2200);
        set("jiali", 100);
        
        set("combat_exp", 3700000);
        set("score", 50000);
 
        set_skill("force", 270);                // �����ڹ�
        set_skill("tiangang-zhengqi", 270);      //�������
        set_skill("unarmed", 270);              // ����ȭ��
        set_skill("kongming-quan", 270);         //����ȭ 
        set_skill("dodge",270);               // ��������
        set_skill("qixing-huanwei", 270);      //���ǻ�λ
        set_skill("parry", 270);              // �����м�
        set_skill("sword", 270);              // ��������
        set_skill("quanzhen-jianfa", 270);      //����� 
        set_skill("taoism", 270);             //��ѧ�ķ�  
        set_skill("literate",270);          //����д�� 
        set_skill("qixing-array",300);  
  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("ȫ���",2,"����");
        
        set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),

        }) );
        
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/obj/greyrobe")->wear();

}
void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        
        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && !present("yingxiong ling", ob) 
        && ( (fam = ob->query("family")) && fam["family_name"] != "ȫ���" ) )
        {
                if( !ob->query_temp("warned") ) {
                        command("say ����˭��  ��ô����ȫ�����԰�����ˣ���");
                        command("say ����������뿪���´ο����������ģ�");
                        ob->set_temp("warned", 1);
                }
                else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
                else {
                        command("say �󵨿�ͽ�����Ҵ���ȫ�����԰������Ұ�����ˣ���������! \n");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
                }
        }       

}



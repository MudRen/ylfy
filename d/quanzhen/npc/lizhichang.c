//��־�� 

#include <ansi.h> 
inherit NPC;
#include "/quest/quest.h"
void consider();

void create()
{
        set_name("��־��", ({"master li","li zhichang", "li", "zhichang"}));
        set("master", "����һ");
        set("gender", "����");
        set("age", 30);
        set("long",
             "����ò���㿡����ȴʮ��Ӣͦ���߸ߵĸ��ӣ����ܽ�׳��\n"
             "��������������쵽ʦ�ŵ�����\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 21);
        set("int", 19);
        set("con", 21);
        set("dex", 19); 
        set("per", 20);
        set("chat_chance", 1);
        set("chat_msg", ({
            "��־��˵�����������С���˵���㺦����ʦ�֣�������Ĺ���������������\n",
     "��־���૵�����ֻҪ�ҵ����ߺ͹�׾Ϳ��Ե���ҩ��������ȥ��ҩ�ˡ���\n",
     "��־����������Ķ���˵��������������ȫ��̵�����ѽ����\n",
//        (: random_move :),
        }));

        set("qi", 850);
        set("max_qi", 850);
        set("jing", 850);
        set("max_jing",850);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);
        
        set("combat_exp", 800000);
        set("score", 80000);
 
        set_skill("force", 120);             // �����ڹ�
        set_skill("tiangang-zhengqi", 120);    //�������
        set_skill("unarmed", 120);           // ����ȭ��
        set_skill("kongming-quan", 120);     //����ȭ 
        set_skill("dodge",130);              // ��������
        set_skill("qixing-huanwei", 130);        //���ǻ�λ
        set_skill("parry", 120);             // �����м�
        set_skill("sword", 120);             // ��������
        set_skill("quanzhen-jianfa", 120);        //����� 
        set_skill("taoism",120);           //��ѧ�ķ�  
        set_skill("literate",120);           //����д��
        set_skill("qixing-array",120);  

  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "tiangang-beidou");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("ȫ���", 3, "����"); 
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/obj/greenrobe")->wear();

}   


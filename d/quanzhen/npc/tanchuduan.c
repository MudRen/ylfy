//tanchuduan.c  ̷����
#include <ansi.h> 
inherit NPC;

void create()
{
        set_name("̷����", ({"tan chuduan", "tan", "chudan"}));
        set("nickname", HIC"������"NOR);
        set("gender", "����");
        set("age", 53);
        set("long",
             "�����Ͻ����ᣬŨü��������ο��࣬��˵����ǰ��ɽ����������\n"
                "������ȫ�����ӵĶ�ʦ�֡������ӡ�̷���ˡ�\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing",1350);
        set("max_jing", 1350);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        
        set("combat_exp", 3000000);
        set("score", 50000);
 
        set_skill("force",290);             // �����ڹ�
        set_skill("tiangang-zhengqi",290);    //�������
        set_skill("unarmed",280);           // ����ȭ��
        set_skill("kongming-quan",280);    //����ȭ 
        set_skill("dodge",280);              // ��������
        set_skill("qixing-huanwei",280 );        //���ǻ�λ
        set_skill("parry",290 );             // �����м�
        set_skill("sword",290 );             // ��������
        set_skill("quanzhen-jianfa",290);        //����� 
        set_skill("taoism",280 );            //��ѧ�ķ�  
        set_skill("literate",280);           //����д��  
  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongmingquan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("ȫ���", 2, "����");
        
        setup();
        
       carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/obj/greyrobe")->wear();

}



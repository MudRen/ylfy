// duanyu.c ����
#include <ansi.h>
inherit NPC;
void create()
{
    set_name("����", ({"duan yu", "duan", "yu"}));
    set("nickname", GRN"��������"NOR);
    set("gender", "����");
    set("age", 20);
    set("long", 
        "����һ�����������������ӡ������Լ⣬����һ�������Ĵ�����\n");
    set("attitude", "peaceful");
    
    set("str", 12);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("chat_chance", 5);
    set("chat_msg", ({
        "����̾�˿�����������������ʱ���ټ������̰�������\n",
        (: random_move :),
    }));
    set("inquiry", ([
        "����" : "�����Ǹ��õط���ɽ��ˮ�㣬�羰���ˡ�\n",
        "������" : "����������ֻ������磬������û���ҷ������\n",
        "��ʦ" : "��....���ҵ�ʦ�������ӡ����Ӻ�ׯ�ӣ����ǵ�ѧ���һ�ûѧȫ�ء�\n",
    ]));
    set("jing", 2000);
    set("max_jing", 2000);
    set("jingli", 2000);
    set("max_jingli", 2000);
    set("qi", 2000);
    set("max_qi", 2000);
    set("neili", 4000);
    set("max_neili", 4000);
    set("jiali",200);
    
    set("combat_exp", 500000);
     
    set_skill("force", 100);        // �����ڹ�
    set_skill("beiming-shengong", 100); // ��ڤ��
    set_skill("unarmed", 120);      // ����ָ��
    set_skill("sword", 120);        // ��������
    set_skill("liumai-shenjian", 120);  // ������
    set_skill("dodge", 150);        // ��������
    set_skill("lingboweibu", 150);      // �貨΢��
    set_skill("parry", 80);         // �����м�
    
    map_skill("sword", "liumai-shenjian");
    map_skill("force", "beiming-shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("parry", "liumai-shenjian");
    map_skill("unarmed", "liumai-shenjian");
    
    setup();
    
    carry_object("/d/city/obj/gangjian");
    carry_object("/clone/cloth/cloth")->wear();
}

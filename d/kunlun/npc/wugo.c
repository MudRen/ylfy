inherit NPC;
inherit F_DEALER;
void create()
{
        set_name(MAG "���" NOR, ({ "wu gu"}));
        set("shen_type", 0);
        set("age",31);
        set("gender", "Ů��");
        set("per",7);
        set("long",
                "ֻ����һ���׵�������˽�һ�㣬˫���������
�����������۾����������������ǳ��ŷ��䡣\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "�����" : "�Ǹ���������һ���һ�ɱ������\n",
                "�ݺ�" : "��ʲô��˼......��\n",
        ]));
      
  setup();
        carry_object("//clone/cloth/pink_cloth")->wear();
}


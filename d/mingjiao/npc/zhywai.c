// zhywai.c
inherit NPC;
void create()
{
        set_name("��Ա��", ({ "zhang yuanwai"}));
        set("gender", "����");
        set("age", 55);

        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 10);
        set("attitude","heroism");
        set("inquiry", ([
           "ţ" : "���⼸�쵹�ǵõ�ͷţ�������������ֲ���������顣",
           "��ţ" : "���ţ�Ǹ���������˵��ʲô�����йأ��ҿɲ�����",
        ]) );

        set("combat_exp", 25000);
        set("shen_type", -1);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        set("chat_chance", 10);
        set("chat_msg", ({
           "��Ա�������������̵ģ��ҵı��������\n",
           "��Ա��˵�����Ƕ���Ҫ�ҵ�Ǯ��Ҳ������һ������Ա���Ǹ�ʲô������!��\n",
           }) );
}


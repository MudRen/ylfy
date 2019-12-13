inherit NPC;
#include "/quest/quest.h"
void create()
{
        set_name("������",({"wang furen","wang","furen"}));
        set("gender", "Ů��");
        set("rank_info/respect", "����");
        set("title","��٢��ɽׯ��");
        set("long", 
              "��������٢��ɽׯ�����ˣ�������ȥ������ʮ�мӣ��������ȴ档\n");
        set("age", 40);
        set("attitude", "friendly");
        set("shen_type", 0);
        set("str", 20);
        set("int", 22);
        set("con", 28);
        set("dex", 23);
        
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 700);
        set("max_neili", 800);
        set("jiali", 0);
        set("combat_exp", 300000);
        set("score", 15000);

        set_skill("dodge",180);
        set_skill("force", 180);
        set_skill("ding-force", 180);
        set_skill("ding-dodge", 180);
        set_skill("parry", 170);
        set_skill("literate", 190);
        set_skill("strike", 180);
        map_skill("force", "ding-force");
        map_skill("dodge", "ding-dodge");
        
        setup();
        carry_object("d/mr/obj/shoe")->wear();
        carry_object("d/mr/obj/red_silk")->wear();
        carry_object("d/mr/obj/skirt")->wear();
        
        create_family("����Ľ��",3,"����");
        set("inquiry", ([
            "name" : "�Ҿ�����٢��ɽׯ�����ˣ��������ѵ�û��ʲô��ʾ��\n",
            "here" : "��������٢��ɽׯ��ׯԺ֮���ڣ��˴���Ϊ�ƽ�¥��\n",
            "rumors" : "������Ǳ���Ľ�ݲ����������ˡ�\n",
            "������" : "�������ҵı���Ů������ɱ�����������⡣\n",
            "Ľ�ݸ�" : "Ľ�ݸ������ǲ�������ֶ�����������Ա�֮����ʩ����ľ��������𽭺���\n",
            "������" : "������������٢��ɽׯ�Ĳ���֮����һ�����Ǳ����ȥ�ˡ�\n",
            "��٢��ɽׯ" : "���������٢��ɽׯ���Ҿ�����������ˡ�\n",
            "��ʩˮ��" : "���������������֮���ڣ�������ʩˮ��Ĳ����������Ƕ�Ķ�ѽ��\n",       
       ]));
}

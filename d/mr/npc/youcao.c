#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�Ĳ�", ({ "you cao", "cao", "you" }));
        set("gender", "Ů��");
        set("age", 20);      
        set("title",HIM"Ѿ��"NOR);
        set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp", 13000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("max_qi",500);
        set("qi",500);
        set("max_jing",500);
        set("neili",500);
        set("max_neili",500);
        set("jiali",0);
        set("score", 2000);

        set_skill("cuff", 50);
        set_skill("parry",40);
        set_skill("ding-dodge",70);
        set_skill("dodge", 70);
        set_skill("force",70);
        set_skill("ding-force",70);

        map_skill("force","ding-force");
        map_skill("dodge","ding-dodge");
        
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
     
        carry_object("d/mr/obj/shoe")->wear();
        carry_object("d/mr/obj/red_silk")->wear();
        carry_object("d/mr/obj/skirt1")->wear();
        set("inquiry", ([
            "name" : "�Ҿ�����٢��ɽׯ��Ѿ���Ĳݡ�\n",
            "here" : "��������٢��ɽׯ���ѵ���û����˵����\n",
            "rumors" : "���ʷ��������辭�����������ʣ�ǧ������������㡣\n",
            "����" : "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�\n",
            "����" : "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����\n",
            "������" : "���������Ҽ�С�㡣\n",
            "����ˮ�" : "����ˮ��ǰ������ס�ĵط��������ﲻԶ��\n",
            "����С��" : "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�\n",
            "��٢��ɽׯ" : "���������٢��ɽׯ�ˡ�\n",
            
       ]));                 
        set("chat_chance",20);
       set("chat_msg",({
                "�Ĳ��������ﵽ����ǧ����������迴���㣬Ҫ����������ɻ��ʵġ���\n",
                
        }) );        
}

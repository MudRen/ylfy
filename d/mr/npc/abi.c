#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "a bi", "a", "bi" }));
        set("gender", "Ů��");
        set("age", 20);      
        set("title",HIM"����Ѿ��"NOR);
        set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp", 13000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
        set("jiali",30);
        set("score", 8000);

        set_skill("cuff", 50);
        set_skill("parry",40);
        set_skill("ding-force",70);
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
            "name" : "����Ľ�ݹ��ӵ�����Ѿ�ߣ��������̣��þ�û�м���Ľ�ݹ����ˡ�\n",
            "here" : "����������ˮ鿣���Ľ����үΪ���չ��Ҹ��Ұ��ŵ�ס����\n",
            "rumors" : "��٢��ɽׯ������ĸ��һ���Ӳ�������ȥ����ɽׯ�������Ƕ����ҡ�\n",
            "��٢��ɽׯ" : "�����ﲻԶ����һС����Ϊ����ӣ�ֻҪ�������ң��Ϳɳ˴�ǰ����\n",
            "Ľ�ݸ�" : "Ľ�ݸ�����������������ˣ����Ա�֮������ʩ���������������\n",
            "�����" : "˳��С��һֱ�����ߣ�����������ˡ�\n",
 ]));           
}

// modified by vikee 2000.11
//����ɽ���ɡ�dhxy-evil 2000.7.5
// lilong ����2002.01.12
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�����", ({ "gui wang", "wang" }));
        set("title",HIR"����"NOR);
        set("age", 300);
        set("attitude", "aggressive");
        set("str", 40);
        set("per", 20);
        set("con", 30);
        set("cor", 30);
        
        set("max_qi", 30000000);
        set("max_jing", 30000000);
        set("max_neili", 30000000);
        set("combat_exp", 2100000000);
        set("max_jingli", 30000000);
        set("neili", 30000000);
        set("jingli", 30000000);
        set("jiali", 10000);
		set("no_suck", 1);

        set_skill("force", 30000);
        set_skill("dodge", 30000);
        set_skill("parry", 30000);
        set_skill("unarmed", 30000);
        set_skill("shushan-force", 30000);
        set_skill("zuixian-steps", 30000);
        set_skill("fumozhang",30000);
        map_skill("dodge", "zuixian-steps");
        map_skill("force", "shushan-force");
        map_skill("unarmed", "fumozhang");
        set("chat_chance_combat", 30);

   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);

        setup();
        carry_object("/clone/cloth/cloth")->wear();

}

void die()
{
        if( environment() ) {
        message("sound", CYN"\n����ǵ�������ԭ���ң���Ϊ�������������ΪֻҪ�ܳԾŰپ�ʮ�Ÿ�����\n����һ�ٸ�����Ϳ��Գ�ȥ������...��\n", environment());
        message("sound", "\n������ֵ������������ϣ��ҷ�����ϣ����ϣ�����ܹ��������뿪�����...ǰ��������鷳�Ļ����������ң���\n", environment());
        message("sound", "\n�������ʧ����Ӱ����...\n"NOR, environment());
        }
        destruct(this_object());
}

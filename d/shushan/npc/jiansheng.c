//jiansheng.c by yushu 2000.11
inherit NPC;
#include <ansi.h>
void create()
{
       set_name("��ɽ��ʥ", ({"shushan jiansheng","jiansheng", "master"}));
       set("title", "��ɽ�ɽ���֮ʥ");
       set("gender", "����");
       set("age", 120);
        set("class", "xiake");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ��");
       set("per", 26);
        set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
        set("int", 30);
       set("max_qi", 10000000);
       set("max_jing", 10000000);
       set("neili", 10000000);
	   set("jingli", 10000000);
       set("max_neili", 10000000);
        set("max_jingli", 10000000);
		set("combat_exp", 2100000000);
         set("jiali",30000);
		 set("no_suck", 1);
       set_skill("literate", 800);
       set_skill("dodge", 1500);
       set_skill("parry",  1500);
       set_skill("unarmed",  1500);
       set_skill("fumozhang", 1500); 
        set_skill("sword",  1500);
     set_skill("songhe-sword",  1500);
         set_skill("shushan-force",  1500);
        set_skill("force",  1500);
        set_skill("zuixian-steps",  1500);
       map_skill("force", "shushan-force");
        map_skill("sword", "songhe-sword");
        map_skill("parry", "songhe-sword");
        map_skill("dodge", "zuixian-steps");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
                  (: cast_spell, "fu" :),
        }) );
        create_family("��ɽ��", 2, "����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
		carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{       ob=this_player();
       if ( !((string)ob->query("gender")=="����")){
       command("shake");
       command("say ��ֻ����ͽ����λ" +RANK_D->query_respect(ob) + "����ȥ�Ҿƽ��ɰɡ�\n");
       return;
       }
       if( (string)ob->query("family/family_name")=="��ɽ��") {
         if ((int)ob->query("combat_exp") < 300000 ) {
        command("say ��ĵ��л����������ҵ��з���������\n");
        return;
        }
        if( (int)ob->query_skill("force", 1) < 500 ) {
      command("say ��λ" + RANK_D->query_respect(ob) + "���������ô��,�㻹����׷�������������Ű�!\n");
        command("sigh");
        return;
        }
       command("smile");
       command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ����Ϊ��ɽ���⡣");
       command("recruit " + ob->query("id") );
        return;
        }
       command("shake");
       command("say ���Ǳ��ɵ���?��" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
       return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "��ɽ��ʥ�״�����");

}

        return 0;
}

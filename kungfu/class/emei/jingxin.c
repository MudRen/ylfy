// jingxin.c ����
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_for_join();
string ask_for_join();

void create()
{
        set_name("����", ({ "jing xin","jing","xin"}));
        set("long",
      "����һλ������ҵ��ã����ڸ�£����ü��Ŀ��\n");

        set("gender", "Ů��");
        set("age", 38);
       set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("inquiry",([
		"���"	: (: ask_for_join :),
		"����"	: (: ask_for_join :),
	]));

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 10);

        set("combat_exp", 2550000);
        set("score", 70000);

        set_skill("force", 190);
        set_skill("dodge", 190);
        set_skill("parry", 190);
        set_skill("sword", 190);
        set_skill("linji-zhuang",190);
        set_skill("zhutian-bu",190);
        set_skill("huifeng-jian", 190);
        set_skill("yugalism", 190);
        set_skill("dushi-jiren", 190);
        set_skill("literate", 190);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "huifeng-jian");

        map_skill("sword", "huifeng-jian");
        map_skill("force","linji-zhuang");

        create_family("������", 4,"����");
        set("class","bonze");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
  }

void init()
{
	add_action("do_kneel", "kneel");
}

string ask_for_join()
{
	object me;

	me = this_player();
 
        if ( (int)me->query("combat_exp") > 100000 && (int)me->query("betrayer") > (int)me->query("K_betrayer"))
        {
         command("heng");
          return "����Ҫ���Ͻ�����ʩ���������Ķ�����ˡ����գ����գ�ƶ�᲻�ܸ�����ȡ�\n";

        }
	if( (string)me->query("class")=="bonze" )
		return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶ�Ὺ�����Ц��\n";

	if( (string)me->query("gender") != "Ů��" )
		return "�����ӷ����գ����գ�ʩ������������ҷ𣬿�ȥ�������ܽ䡣\n";

	me->set_temp("pending/join_bonze", 1);
    	return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
	object me = this_player();

	string *prename =
	 ({ "��" });

	string name, new_name;

	if( !me->query_temp("pending/join_bonze") )
		return 0;
     
	message_vision(
		"$N˫�ֺ�ʮ�����������ع���������\n\n"
		"$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n",
		me, this_object() );
	name = me->query("name");
	new_name = prename[random(sizeof(prename))] + name[2..3];
	command("say �ӽ��Ժ���ķ�������" + new_name + "��");
        command("say ������ʦ�Ļ������Ҿ���ʦ�㡣");
        command("smile");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_betrayer", (int)me->query("betrayer") );

	return 1;
}
void attempt_apprentice(object ob)
{
     
        command("say ���գ�ƶ��ֻ����ȡ�");
        command("say ������ʦ�Ļ������Ҿ���ʦ�㡣");
}

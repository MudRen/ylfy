// jingfeng.c ����
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_yao();
string ask_jian();
void create()
{
        set_name("����", ({ "jing feng","jing","feng"}));
        set("long",
      "����һλ����ʦ̫��ֻ����üĿ�״�����������һ�ѳ�������Ȼ��Ȼ���й����ϡ�\n");
        set("gender", "Ů��");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 22);
        set("con", 20);
        set("dex", 21);

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);

        set("combat_exp", 4000000);
        set("score", 80000);

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 205);
        set_skill("sword", 205);
        set_skill("linji-zhuang",200);
        set_skill("zhutian-bu",200);
        set_skill("huifeng-jian", 210);
        set_skill("yugalism", 250);
        set_skill("dushi-jiren", 250);
        set_skill("literate", 200);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "huifeng-jian");

        map_skill("sword", "huifeng-jian");
        map_skill("force","linji-zhuang");

	set("inquiry", ([
		"��ҩ" : (: ask_yao :),
              	"����" : (: ask_jian :),
	]));

        set("gao_count",3);
        set("jian_count",2);
        create_family("������", 4,"����");
        set("class","bonze");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
  }

string ask_yao()
{
	mapping fam; 
	object ob;
        
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
        if (this_player()->query("qi")>=this_player()->query("max_qi"))
                return "��δ�����ˣ�����ҩ����ʲô��";
        if (ob = present("tianxiang gao", this_player()))
                return "�����ϲ��Ǵ��ű�����ҩ����";
        if (query("gao_count") < 1)
		return "�������ˣ�������ҩ�Ѿ������˱��ɵ��ӡ�";
	add("gao_count", -1);
	ob = new("/d/emei/obj/tianxiang-gao");
	ob->move(this_player());
	return "�������б�����ҩ������ȥ���˰ɡ�";
}

string ask_jian()
{
	mapping fam; 
	object ob;
        
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
        if (query("jian_count") < 1)
		return "������û��ʲô�����ø������´������ɡ�";
        if (ob = present("ruanjian", this_player()))
                return "�����ϲ��Ǵ�����������ô����Ҫ��";
	add("jian_count", -1);
	ob = new("/d/emei/obj/ruanjian");
	ob->move(this_player());
	return "��������һ����������ȥ�ðɡ�";
}
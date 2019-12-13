// huqingniu.c ����ţ

#include <ansi.h>
inherit NPC;

string ask_liao();
string ask_me();

void create()
{
        set_name("����ţ", ({ "hu qingniu", "hu" }));
        set("nickname", YEL"����ҽ��"NOR);
        set("long", 
                "���������̵ļ�������ҽ�ɺ���ţ��\n"
                "ȫ���������ƣ�����Щ�ɷ���ǵ�ζ����\n");
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 30);
        
        set("max_qi", 1200);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 100000);
        set("shen",3000);
        set("score", 10);

        set_skill("force", 80);
        set_skill("shenghuo-shengong", 60);
        set_skill("dodge", 50);
        set_skill("qingyunwu", 40);
        set_skill("shenghuo-quan", 60);
        set_skill("parry", 60);
        set_skill("literate", 80);

        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingyunwu");
        map_skill("unarmed", "shenghuo-quan");
        map_skill("parry", "shenghuo-quan");
        create_family("����", 35, "����");
        set("inquiry", ([
              "����" : (: ask_liao :),
              "��ҩ" : (: ask_me :),
        ]));
	 set("yao_count", 1);
        setup();
        carry_object("/clone/weapon/dagger");        
        carry_object("/clone/cloth/cloth")->wear();
}

string ask_liao()
{
       mapping fam; 

       object ob;
        ob=this_player();
      write( "����ţ�������㿴����֪����Щʲô���⡣\n"); 
      if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
               return RANK_D->query_respect(this_player()) + 
               "�뱾��������������֪�˻��Ӻ�̸��";
      if ((int)this_player()->query("eff_qi") >= (int)this_player()->query("max_qi")) 
        return RANK_D->query_respect(this_player()) + "��Ѫ���㣬����ҽ�ΰ���";
         
       ob->set("eff_jing", (int)ob->query("max_jing"));
       ob->set("jing", (int)ob->query("max_jing"));
       ob->set("eff_qi", (int)ob->query("max_qi"));
       ob->set("qi", (int)ob->query("max_qi"));
       write( HIW "����ţ�Ӱٻ����ע��һ������������û���ů����ģ�����ʧȥ����Ѫ���ص������� \n"NOR);

       return "�������������"; 

}

string ask_me()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("yao_count") < 1)
                return "�������ˣ����ɵ�����ʥҩ���ڴ˴���";
        add("yao_count", -1);
        ob = new(__DIR__"obj/heiyu");
        ob->move(this_player());
        return "�ðɣ���ƿ������������û�ȥ�ú����ˡ�";
}

void unconcious()
{
    command("say �Һ���ţһ������������Э�ȣ� �ߣ������ø������ˣ� ���������Ұɣ�");
        tell_room(environment(this_object()), "����ţ˵�꣬�ͳ�һ��ذ�ף������Լ�����һ�壮\n");
        ::die();
}

void die()
{
        unconcious();
}


// suxingh.c
// shilling 97.2
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_book();
void create()
{
    set_name("���Ǻ�",({"su xinghe","su"}));
    set("gender", "����" );
    set("nickname", "�ϱ�����");
    set("shen_type", 0);
    set("age",60);
    set("str", 30);
    set("con", 30);
    set("int", 45);
    set("dex", 35);
    set("per", 30);
    set("no_clean_up",1);
    set("long",
"���˾��Ǻųƴϱ����˵����Ǻӣ���˵�������Ʊ磬 \n"
"��һ�������е����ߣ��������书Ҳ��������֪��\n");
    set("combat_exp", 500000);
    set("attitude", "peaceful");
    set("book_count", 1);
    set("chat_chance", 1);
    set("inquiry", ([
//        "���ܵص�":(:ask_me:),
        "�ؼ�":(:ask_book:),
    ]) );
    set("max_qi", 3400);
    set("max_jing", 400);
    set("neili", 6500);
    set("max_neili",3500);
    set("jiali", 60);
    set_skill("force", 200);
    set_skill("dodge", 200);
    set_skill("unarmed", 200);
    set_skill("parry", 200);
    set_skill("blade", 200);
    set_skill("lingboweibu", 200);
    set_skill("beiming-shengong", 200);
    set_skill("ruyi-dao", 200);
    set_skill("liuyang-zhang", 200);
    set_skill("zhemei-shou", 200);
    set_skill("literate", 200);
    map_skill("unarmed", "liuyang-zhang");
    map_skill("blade", "ruyi-dao");
    map_skill("dodge", "lingboweibu");
    map_skill("force", "beiming-shengong");

    create_family("��ң��", 2, "����");
    set("title","��ң�ɵڶ��������");
    setup();
    carry_object("clone/cloth/cloth")->wear();
    carry_object("clone/weapon/blade")->wield();
}

void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("shake"+ ob->query("id")); 
        command("say " + RANK_D->query_respect(ob) + 
            "�Ƿ�Ӧ����ѧ���϶��µ㹦��");
        return;
    }
    command("say �ðɣ��Ҿ��������ˣ����Ҫ���Ŭ������");
    command("recruit " + ob->query("id"));
    ob->set("class","shaman");
 }
string ask_book()
{
    object ob;
    mapping fam; 
    ob=this_player();
    if (!(fam = ob->query("family")) 
        || fam["family_name"] != "��ң��")
    {
        return"��Ҫ�ؼ��͵ü�����ң�ɡ�";
    }
    command("sigh");
    return"���ɵ��书�ؼ�����һ�������ܵĵط�����Ҳûȥ����";
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xiaoyao");
}
mixed hit_ob(object me,object victim,int damage)
{
   if (!living(this_object()) )  return;
   switch( random(2)) { 
   case 0:
   command("exert maxsuck "+victim->query("id"));
   break;
   case 1:
   command("exert suck "+victim->query("id"));
   break;
    }
}

// rong.c ����
inherit NPC;
inherit F_MASTER;
string ask_chicken();
void create()
{
    set_name("����", ({"huang rong", "huang", "rong"}));
    set("title", "�һ�����������Ů");
    set("gender", "Ů��");
    set("age", 18);
    set("long", 
        "�����һ������Ķ���Ů�������ڵ����������������������Ů�������۰���\n"
        "���������ѷ��ϲ���Ĵ����ܡ�\n");
    set("attitude", "peaceful");
    
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 86);
    set("per",30);
    set("qi", 800);
    set("max_qi", 800);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 10000);
    set("max_neili", 9000);
    set("jiali", 0);
    
    set("combat_exp", 583200);
    
    set_skill("force", 180);
    set_skill("bibo-shengong", 180);
    set_skill("unarmed", 180);
    set_skill("luoying-zhang", 180);
    set_skill("dodge", 180);
    set_skill("anying-fuxiang", 180);
    set_skill("parry", 180);
    set_skill("sword", 180);
    set_skill("luoying-shenjian",180);
    
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
    
    create_family("�һ���", 2, "����");
    set("inquiry", ([
        "�л���" : (: ask_chicken :)
    ]) );
    setup();
    carry_object(__DIR__"obj/ruanwei")->wear();
    carry_object(__DIR__"obj/shudai")->wear();
}
void init()
{
    object ob;
    mapping myfam;
        
    ::init();
    add_action("do_kiss", "kiss");
    if (interactive(ob = this_player()) && !is_fighting()) {
        myfam = (mapping)ob->query("family");
        if ((!myfam || myfam["family_name"] != "�һ���") &&
            (!wizardp(ob)))
        {
            remove_call_out("saying");
            call_out("saying",2,ob);
        }
    }
}
int do_kiss ( string arg )
{
   object ob ;
   ob = this_player () ;
   if( !arg || !id(arg))
     return 0;
   
   if ( (string) ob -> query ("gender") == "����" )
      command ("say ����������������"+ ob->query("name") + "Ҫ�����ң�\n") ;
   else
      message_vision("\n���ض�$NЦ�������ý�㲻Ҫ����������������\n", ob);
   return 0 ;
}
void saying(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    if ((string)ob->query("gender") == "����")
        message_vision("\n�������־���֮ɫ��������$Nһ�ۣ�˵����������ʲô�ˣ�"
        "�����Ҵ��ҵĹ뷿��\n�ٲ�����ȥ��������ô���㣡��\n", ob);
    else
        message_vision("\n���ؿ��˿�$N��˵�������þ�û���������ˣ�"
        "��֪��λ�������Ҿ�������Ϣ��\n", ob);
}
void attempt_apprentice(object ob)
{
    command("say �������ôС����ͽ�ܣ�������Ц��������");
}
string ask_chicken()
{
    if (this_player()->query_temp("marks/��", 1))
        return "���������ô��ô������˵����ꤻ���\n";
    else
    {
        say("�ض�������˵���л������Ǻ��������ز����ҵ�������˺ô�ľ��Ÿ㵽������\n"
            "�����ط�������������ʲô��\n");
        this_player()->set_temp("marks/��", 1);
        return "����Գ�ȥ�ˡ�\n";
    }
}

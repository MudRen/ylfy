// masteryue.c
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("��̫��", ({ "master he", "master","he" }) );
        set("title", YEL "��������" NOR);
        set("gender", "����");
        set("age", 42);
        set("long",
         "���������������ź�̫�塣������ȥ�Ǹ����Ƶ������ˣ�
�������Ǳ�����񣬺���һ����ʦ�ķ緶��\n");        
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 35);
        set("con", 50);
        set("per", 28);
        set("dex", 80);
        set("jingli",1000);
        set("max_jingli",2000);
        set("neili", 11500);
        set("max_neili", 5500);
        set("jiali",300);
        set("rank_info/respect", "������");        
        set("combat_exp",3300000);
 
           set_skill("force", 290);
           set_skill("dodge", 290);
           set_skill("parry", 290);
           set_skill("xuantian-wuji", 290);
           set_skill("sword", 290);
           set_skill("literate",290);
           set_skill("liangyi-jian", 290);
           set_skill("yaoming-dodge", 320);
           set_skill("kunlun-zhang",300);
           set_skill("unarmed",300);

           set("inquiry", ([
                "�����" : "���Ǳ�����ʦү��\n",
                "����ʥ" : "���Ǳ�����ʦү��\n",
                  "���" : "�����ҵ�С檡������������ڲ��ˡ�\n",
                "�����" : "�꣡����ô������\n",
           ]));

           set("chat_chance", 5);
           set("chat_msg", ({
           "��̫��̾������õĲ�Խ��Խ���ˣ��� . . . \n",
           "��̫��˵����˭�����κ���õĲ�����һ����л����\n",
           }));
           
           map_skill("dodge", "yaoming-dodge");
           map_skill("force", "xuantian-wuji");
           map_skill("parry", "liangyi-jian");
           map_skill("sword", "liangyi-jian");
           map_skill("unarmed","kunlun-zhang");   
 
    create_family("������", 14, "����");
    setup();
    carry_object("//clone/cloth/long_cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
void init()
{       
        object ob; 
        ob = this_player();
        ::init();
        if( interactive(ob) && !is_fighting() )  { 
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if ((string)this_player()->query("family/family_name")!="������"){
        switch( random(3) ) {
                case 0:
                        say( "��̫��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "���������������кι�ɡ�\n");
                        break;
                case 1:
                        say( "��̫����˴��֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������ԭ������ʶʲô��ҽ��\n");
                        break;
                case 2:
                        say( "��̫�幰�˹��֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����ѧ��ҽ����\n");
                        break;
                   }
        } else {
        switch( random(2) ) {
                case 0:
                        say( "��̫����˴��֣�˵������ͽ���������������ԭ������ʶʲô��ҽ��\n");
                        break;
                case 1:
                        say( "��̫�����ε�Ц������ͽ���������ѧ��ҽ����\n");
                        break;
             }
       }
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "����" )
          {        
        command("say �Ҳ���Ů���ӵģ����ﻹ�������ʦ�ɡ�");
            return;
                }

        if ((int)ob->query_skill("force", 1) < 50) 
           {
        command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������ڹ��ķ���");
        return;
       }
    command("recruit " + ob->query("id"));

}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}

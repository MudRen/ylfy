// wujiang.c �佫
inherit NPC;
void create()
{
        set_name("�����佫", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "����");
        set("age", random(10) + 30);
        set("str", 25);
        set("dex", 16);
        set("long", "��վ�������ȷ��˵���������硣\n");
        set("combat_exp", 150000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set_skill("unarmed", 120);
        set_skill("force", 120);
        set_skill("sword", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 60);
        set("neili", 800); 
        set("max_neili", 800);
        set("jiali", 20);
        setup();
        carry_object("clone/weapon/gangjian")->wield();
        carry_object("clone/armor/tiejia")->wear();
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
        add_action("do_kill","hit");
}
int do_kill(string arg)
{
        call_out("kill",1,arg,this_player());
        this_player()->set_temp("dalikill", 1);
        return 0;
}
int kill(string arg,object obj)
{
        object ob;
        int i;
        if (!obj)
                return  0;
        if (environment(obj)!=environment())
                return 0;
        if (this_object()->id(arg)){
        command("say ���ܣ�����������·�� �ֵ��ǣ��ϣ�");
        for(i=0; i<4; i++) {
                if( objectp( ob = present("guan bing", environment(this_object())) ) )
                     if (!ob->is_killing(this_player()))
                                 ob->kill_ob(this_player());    
        }
        }
        return 0;
}
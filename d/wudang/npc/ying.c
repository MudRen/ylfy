// yin.c ����ͤ
inherit NPC;
void create()
{
    set_name("����ͤ", ({
 "yin litin", "yin" }));
    set("nickname", "�䵱����");
    set("long", 
        "�����������������������ͤ��\n"
        "��������ʮ�꣬�����ܸɣ�������������һ�\n");
    set("gender", "����");
    set("age", 30);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 26);
    set("int", 30);
    set("con", 26);
    set("dex", 28);
    
    set("max_qi", 1200);
    set("max_jing", 800);
    set("neili", 1500);
    set("max_neili", 1500);
    set("jiali", 100);
    set("combat_exp", 125000);
    set("shen", 60000);
    set_skill("force", 80);
    set_skill("taiji-shengong", 60);
    set_skill("dodge", 80);
    set_skill("tiyunzong", 60);
    set_skill("unarmed", 80);
    set_skill("taiji-quan", 60);
    set_skill("parry", 80);
    set_skill("sword", 100);
    set_skill("taiji-jian", 100);
//  set_skill("taoism", 80);
    set_skill("literate", 80);
    map_skill("force", "taiji-shengong");
    map_skill("dodge", "tiyunzong");
    map_skill("unarmed", "taiji-quan");
    map_skill("parry", "taiji-jian");
    map_skill("sword", "taiji-jian");
    create_family("�䵱��", 2, "����");
    setup();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/whiterobe")->wear();
}
void init()
{
::init();
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
    mapping fam;
        int i ;
    object me;
    object* obj;
    me = this_object();
    if (interactive(ob) 
    && !environment(ob)->query("no_fight"))
    {
         if (!(fam = ob->query("family")) || fam["family_name"] != "�䵱��")
        {
                   if (ob->query("shen")>-1000)      
            {
            command("say �������䵱�صأ���������Ϲ��ʲô��");
            obj = all_inventory(environment(me));
            for(i=0; i<sizeof(obj); i++) {
            if(obj[i]==this_player()) continue;
            if(obj[i]==me) continue;
            if(obj[i]->query("title")=="����") {
                command("say �����,���ڴ˺�����Ϊ,����!!");
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, obj[i]); 
                }
            }
            }
            else{
            command("say һ��Ҫɱ�����⽭�����࣡");
            me->set_leader(ob);
            remove_call_out("kill_ob");
            call_out("kill_ob", 1, ob); 
        
            }
        }    
    }       
}

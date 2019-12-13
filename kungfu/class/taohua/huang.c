#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
    set_name("��ҩʦ", ({"huang yaoshi", "huang", "yaoshi"}));
    set("nickname", HIY "��а" NOR );
    set("gender", "����");
    set("age", 42);
    set("long", 
        "�������һ����������ºö�ȫ�ɼ��ģ���˱��˳�������а����\n");
    set("attitude", "peaceful");
    
    set("str", 100);
    set("int", 80);
    set("con", 86);
    set("dex", 240);
    set("chat_chance", 1);
    set("chat_msg", ({
        "��ҩʦ̾�˿����������� ���� �ض�������ĺ��ӣ���С��û���� ������\n",
        "��ҩʦ��ͷ��˼����Ȼ���\n",
    }));
    set("inquiry", ([
        "����"     : "���ֱ����Ů���Ĺ����� \n",
        "�����澭" : "������ܰ���ȡ���澭�ϲᣬ��һ������л�㡣\n",
    ]));
	
    set("qi", 3000000);
    set("max_qi", 3000000);
    set("jing", 1500000);
    set("max_jing", 1500000);
    set("max_jingli", 200000);
    set("jingli", 30000);
    set("neili", 4000000);	
    set("max_neili", 500000);
    set("jiali", 13500);
    set("xyzx_sys/level", 1500);
    set("combat_exp", 60000000);
     
    set_skill("force", 2900);   
    set_skill("finger", 1900);	
    set_skill("count", 1300);	    
    set_skill("unarmed", 2000);  
    set_skill("dodge", 2100);  
    set_skill("parry", 2900);
    set_skill("sword", 2900);  
    set_skill("literate",2550); // ����ʶ��
	set_skill("luoying-zhang", 1860);
	set_skill("lanhua-shou", 1900);		
    set_skill("yuxiao-jianfa",1800);
	set_skill("bibo-shengong", 2190);
    set_skill("tanzhi-shentong", 1900);
    set_skill("xuanfeng-tui",1800);
	set_skill("anying-fuxiang", 1800);
	set_skill("luoying-shenjian", 1950);
    set_skill("qimen-wuxing",1800);
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "tanzhi-shentong");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("finger"  , "tanzhi-shentong");	
    map_skill("parry"  , "yuxiao-jianfa");
    map_skill("sword"  , "yuxiao-jianfa");	
    
    create_family("�һ���", 1, "����");
    set("chat_chance_combat", 80); 
	setup();
    
    carry_object(__DIR__"obj/yuxiao")->wield();
    carry_object(__DIR__"obj/bupao")->wear();
    carry_object("/clone/book/jiuyin2");
	carry_object("d/taohua/obj/xiang");
    
}
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say �Ҳ������ʲ�ĵ��ӣ�����ذɣ�");
        return;
    }
    if ((int)ob->query_skill("bibo-shengong",1) < 50 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
        return;
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say ���һ��������������������������ֳ�������򽻵�������ذɣ�");
        return;
    }
    command("say �ܺã��ܺá�");
    command("recruit " + ob->query("id"));
}
int accept_object(object who, object ob)
{
    
    if ( (string) ob->query("id") =="jiuyin zhenjing1" ) {
        if (!(int)who->query_temp("tmark/��")) who->set_temp("tmark/��", 0);
        message_vision("��ҩʦ���˿�$N�������ؼ������˵�ͷ��˵����\n"
                               "�ѵ��㽫�澭�ͻء������ҵĶ����Ҿ������ˡ�\n"
                               "��Ϊ����,����Դ�������ѧ�㹦��\n", who);
        who->add_temp("tmark/��", 120);
        return 1;
    }
    return 0;
}
int prevent_learn(object me, string skill)
{
        if ((int)me->query_temp("tmark/��") && me->query("family/family_name")!="�һ���")
        {
        if (!(int)me->query_temp("tmark/��") )
        return 1;
      else
        return 0;
      }else return ::prevent_learn(me,skill);
}
int recognize_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
   if (mapp(myfam))
        if ( myfam["family_name"] == "�һ���") return 1 ;
        if ((int)ob->query_temp("tmark/��") == 1 )
        message_vision("��ҩʦ���˿�$N��˵��������������˭Ҳ��Ƿ˭,\n"
                          "�㲻Ҫ������ѧϰ�����ˡ�\n", ob);
        if (!(int)ob->query_temp("tmark/��"))
                return 0; 
        ob->add_temp("tmark/��", -1);
        return 1;
}

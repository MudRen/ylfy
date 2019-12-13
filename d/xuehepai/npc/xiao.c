// made by lks

#include <ansi.h>
#include "xiaojob.h"

inherit NPC;
inherit F_MASTER;
int ask_me();
int ask_job();
#include "xiao.h"
#include "cloth.h"
void heal_ob();
void recover_ob();

void create()
{
        set_name("������",({"xiao xiaotian","xiao"}));
        set("nickname",HIR"��ڤѪū"NOR);
	set("gender","����");
	set("int",30);	
	set("con",30);
	set("str",30);
	set("dex",30);
	set("bac",40);
	set("age",40);
	set("attitude","peaceful");
        set("combat_exp",5000000);
        set("shen",1000);
	set("long",
"Ӣ������,��ʼ�տ�����һ�����֣����Ҳѳ���ˡ�\n"
	);
        set("neili",20000);
        set("jingli",18000);
        set("max_neili",20000);
        set("max_jingli",18000);
        set_skill("literate",100);
        set_skill("cuff",150);
        set_skill("parry",250);
        set_skill("dodge",250);
        set_skill("youran-bu",250);
        set_skill("tianhe-jian",250);
        set_skill("sword",250);
        set_skill("force",250);
        set_skill("taoism",200);
        set_skill("feixue-quan",250);
        set_skill("throwing",250);
        set_skill("huaxue-shenzhen",250);
        set_skill("huaxue-dafa",250);
        map_skill("force","huaxue-dafa");
        map_skill("dodge","youran-bu");
        map_skill("cuff","feixue-quan");
        map_skill("sword","tianhe-jian");
        map_skill("throwing","huaxue-shenzhen");
        prepare_skill("cuff","feixue-quan");
	
       create_family("Ѫ����",13,"����");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
        set("chat_chance", 2);
	set("chat_msg", ({
		(: heal_ob :),
	}));
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: exert_function, "xisui" :),
                (: exert_function, "xuewu" :),
                (: recover_ob :),
	}) );
       set("inquiry",([
              "Ѫ��" : (: ask_me :),
              "job" : (: ask_job :),
              "xueyi" : (: ask_me :),
       ]));
}


	
void heal_ob()
{
	command("yun heal");
	command("yun heal");
	command("yun heal");
	command("yun recover");
	return;
}

void recover_ob()
{
	command("yun recover");
	return;
}

int ask_me()
{
           object ob;
           mapping fam;

           object me=this_player();

           fam=(mapping)me->query("family");

           if (!fam || fam["family_name"]!="Ѫ����")
           {
                  command("say ���뱾�ɲ��޹ϸ𣬴˻��Ӻ�˵��");
                  return 1;
           }
           else if (fam["master_id"]!="xiao xiaotian")
           {
                  command("say �㲻���ҵĵ��ӡ�");
                  return 1;
           }
           if (me->query("combat_exp")<2000000)
           {
                  command("say ���ʵս����̫���ˡ�");
                  return 1;
           }
             if (me->query("max_neili")<300)
           {
                  command("say ���������Ϊ̫���ˡ�");
                  return 1;
           }
	if (query("yi"))
	{
		command("say Ѫ���Ѿ��������ˡ�");
		return 1;
	}
	command("say �ðɣ��Ұ�Ѫ�����㡣");
	set("yi",1);
	ob=new("/d/xuehepai/obj/xueyi");
	ob->move(me);
	return 1;
}

int ask_job()
{
        object me;
        object ob;
        mapping myfam;
        me=this_player();

        myfam=me->query("family");
        
        if ( !myfam || myfam["family_name"] != "Ѫ����" )
        {
                command("say "+RANK_D->query_respect(me)+"������Ѫ���ɵĵ��ӣ������������ͷ����أ�");
                return 1;
        }
        
        if (me->query_temp("job_start"))
        {
                command("say ���Ѿ��й����ˣ�������ȥ��");
                return 1;
        }
        
          if (me->query("combat_exp")>40000000)
        {
                command("say "+RANK_D->query_respect(me)+"����ʱ�����书�ˣ���ЩС�¾Ͳ����鷳���ˡ�");
                return 1;
        }
        
        tell_object(me,"�ð�,��˵��ɽɽ���ϵ�ʯͷ���ʲ���\n");
        tell_object(me,"��ȥ��һ���������Ҫ��һЩ������\n");
         if (!(ob=present("hammer",me)))
         {
         ob=new("/d/xuehepai/obj/hammer");
         ob->move(me);
           }
        me->set_temp("job_start",1);
        return 1;
}



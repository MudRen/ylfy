// made by lks

#include <ansi.h>

inherit NPC;
int ask_me();
inherit F_MASTER;
#include "xiao.h"
#include "huajob.h"
#include "cloth.h"
void heal_ob();
void recover_ob();

void create()
{
        set_name("��Σ¥",({"hua weilou","hua"}));
        set("nickname",WHT"������"NOR);
       set("shen_type",-1);
        set("gender","����");
        set("int",30);  
        set("con",30);
        set("str",30);
        set("dex",30);
        set("bac",40);
        set("age",40);
        set("gu",1);
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
        set_skill("literate",1000);
        set_skill("cuff",450);
        set_skill("parry",350);
        set_skill("dodge",350);
        set_skill("jieniu-dao",350);
        set_skill("blade",350);
        set_skill("youran-bu",350);
        set_skill("tianhe-jian",350);
        set_skill("sword",350);
        set_skill("force",150);
        set_skill("taoism",300);
        set_skill("feixue-quan",350);
        set_skill("huaxue-dafa",350);
        map_skill("blade","jieniu-dao");
        map_skill("force","huaxue-dafa");
        map_skill("dodge","youran-bu");
        map_skill("cuff","feixue-quan");
        map_skill("sword","tianhe-jian");
        prepare_skill("cuff","feixue-quan");
        
       create_family("Ѫ����",13,"����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
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
                 "job" : (: ask_job :),
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

/*
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
           else if (fam["master_id"]!="hua weilou")
           {
                  command("say �㲻���ҵĵ��ӡ�");
                  return 1;
           }
           if (me->query("combat_exp")<300000)
           {
                  command("say ���ʵս����̫���ˡ�");
                  return 1;
           }
           if (!query("gu"))
           {
                 command("say ������Ѿ��������ˡ�");
                 return 1;
            }
                  command("say �ðɣ��Ұ�����Ľ����㡣");
                   set("gu",0);
                  ob=new("/d/xuehepai/obj/gu");
                  ob->move(me);
                  return 1;
}

*/


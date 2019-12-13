// liang.c ��ԯ��
// marry 99.8

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_me();
void create()
{
        set_name("��ԯ��", ({ "xuanyuan liang", "liang" }));
        set("nickname", HIY "��������" NOR);
        create_family("����������", 2,"����ʹ");
        set("jihao",1);
        set("long","�����ǳ��������ſ�ɽʼ��Ĵ���ӡ�������������ԯ����");
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 30);
        set("dex", 30);
        
        set("max_qi", 400000);
        set("max_jing", 43000);
        set("neili", 300000);
        set("max_neili", 500000);
        set("jiali", 150);
        set("combat_exp", 90000000);
        set("score", 500000);

        set_skill("force", 810);
        set_skill("dodge", 820);
        set_skill("unarmed",740);
        set_skill("parry", 825);
        set_skill("axe", 860);
        set_skill("literate", 900);
        set_skill("wangxiang-fufa", 850);
        set_skill("shuiyue", 830);
        set_skill("wangran-xinfa", 840);
        set_skill("cxwx-quan", 760);
    
        map_skill("force", "wangran-xinfa");
        map_skill("axe", "wangxiang-fufa");
        map_skill("dodge", "shuiyue");
        map_skill("unarmed", "cxwx-quan");
        map_skill("parry", "wangxiang-fufa");
        map_skill("dodge", "shuiyue");
               
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "axe.jifeng" :),
                (: perform_action, "axe.wang" :),
                (: exert_function, "recover" :),
                (: perform_action, "unarmed.tian" :) ,
          }) );
        set("inquiry", ([
                "�������" : (: ask_me :),
        ]));
        setup();
        carry_object("/d/cxwxm/obj/shenfu.c")->wield();
        carry_object("/d/cxwxm/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        if (!ob->query("chuhuan")) {
                command("say ����ȥ���ҵ�ͽ�ܰɣ�");
                return;
}
        if ((int)ob->query_skill("wangran-xinfa", 1) < 400) {
                command("say ���ŵ��书�����ķ��������������ߣ�"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ������Ȼ�ķ��϶��µ㹦��");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say ��������޳�֮ͽ������ɣ�");
                command("say �����ְ��࣬" + RANK_D->query_respect(ob) +
                        "����ɣ�");
                return;
        }
        if ((int)ob->query("per") < 30) {
                command("say �����书�Ǿ�����ò����ϰ�ã�");
                command("say �㻹��ȥ���ݺ�������!");
                return;
        }
 
        if (ob->query_int() < 80) {
                command("say �����书ȫƾ�������롣");
                command("say Ҫ���޵���߾��磬������Ի�����");
                command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
        }
   if ((string)ob->query("gender")=="����")
   {
                message_vision("��ԯ����ϸ��������Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
       command("chat �����������Һ�������ˣ�");
       command("chat �ã���ס�ҵĵ����Ժ���������һ��Ҫ�ҳ��ĵ�Ů��Ӵ��");
                return;}
   else
      {
                message_vision("�㲻�����ˣ����ɣ�\n",ob);
       return;}
        

}

int ask_me()
{
        object me,ob;
        object wuqi;
        me = this_player();
       ob = this_object(); 
      if (((me->query ("family/family_name"))!="����������")||       (me->query("shen",1) < 5000000) || (ob->query_temp("û��")))
      {
       command("say �����ɱ��̫�أ����ʺ����ã�");
      }
      else
      {
       command("say ������Ա������Ĺ����������ȥ���ԣ�");
       wuqi=new("/d/cxwxm/obj/guifu");
       wuqi->move(me);     
       add_temp("û��",1);
      }
      return 1;
}



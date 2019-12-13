#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�Ϲٷɷ�", ({ "shangguan feifeng", "feng","feifeng" }));
        set("nickname", HIG "����Ů" NOR);
        create_family("����������", 2,"����");
        set("jihao",1);
        set("long","�����ǳ��������ŵڶ�������������Ů�Ϲٷɷ");
        set("gender", "Ů��");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 30);
        set("dex", 30);
        
        set("max_qi", 400000);
        set("max_jing", 200000);
        set("neili", 300000);
        set("max_neili", 300000);
        set("jiali", 150);
        set("combat_exp", 300000000);
        set("score", 500000);

        set_skill("force", 1450);
        set_skill("dodge", 1420);
        set_skill("unarmed",1500);
        set_skill("parry", 1440);
        set_skill("whip", 1500);
        set_skill("literate", 2000);
        set_skill("chixin-bianfa", 1500);
        set_skill("shuiyue", 1420);
        set_skill("wangran-xinfa", 1440);
        set_skill("cxwx-quan", 1400);
    
        map_skill("force", "wangran-xinfa");
        map_skill("whip", "chixin-bianfa");
        map_skill("dodge", "shuiyue");
        map_skill("unarmed", "cxwx-quan");
        map_skill("parry", "chixin-bianfa");
        map_skill("dodge", "shuiyue");
             
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "whip.juan" :),
                (: perform_action, "whip.mi" :),
                (: exert_function, "recover" :),
                (: perform_action, "unarmed.tian" :) ,
          }) );


        setup();
        carry_object("/d/cxwxm/obj/whip.c")->wield();
        carry_object("/d/cxwxm/obj/siyi.c")->wear();
}

void attempt_apprentice(object ob)
{
        if (!ob->query("mengsha")) {
                command("say ����ȥ���ҵ�ͽ�ܰɣ�");
                return;
}
        if ((int)ob->query_skill("wangran-xinfa", 1) < 400) {
                command("say ���ŵ��书�����ķ��������������ߣ�"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ������Ȼ�ķ��϶��µ㹦��");
                return;
        }
        if ((int)ob->query("betrayer") != 0) {
                command("say ��������������޳�֮ͽ�������");
                command("say ��������࣬" + RANK_D->query_respect(ob) +
                        "����ɣ�");
                return;
        }
        if ((int)ob->query("per") < 30) {
                command("say ������ϧ�����ò������");
                command("say �㻹��������Ͷ̥����!");
                return;
        }
 
        if (ob->query_int() < 80) {
                command("say �����书ȫƾ�������롣");
                command("say Ҫ���޵���߾��磬������Ի�����");
                command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
        }
   if ((string)ob->query("gender")=="Ů��")
   {
                message_vision("�ϹٷɷﴹĿ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
       command("chat ����������������");
       command("chat �ã��Ҿ�������������ӣ��Ժ�Ҫ�ú����룡");
                ob->set("cxwxmt",1);
                return;}
   else
      {
                message_vision("�����ﳤ����Ů�ˣ�ȥ�������ɣ�\n",ob);
       return;}
        

}

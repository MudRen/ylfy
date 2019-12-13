// chuhuan.c ����
// marry 99.8

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({ "chu huan", "chu","huan" }));
        set("nickname", HIW "���п�" NOR);
        create_family("����������", 3,"����");
        set("jihao",1);
        set("long","�����ǳ��������ŵĴ�ʦ�֡����п͡�������");
        set("gender", "����");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 30);
        set("dex", 30);
        
        set("max_qi", 35000);
        set("max_jing", 5000);
    set("max_jingli", 200000);
        set("neili", 200000);
        set("max_neili", 100000);
        set("jiali", 300);
        set("combat_exp", 50000000);
        set("score", 300000);

        set_skill("force", 420);
        set_skill("dodge", 350);
        set_skill("unarmed",300);
        set_skill("parry", 400);
        set_skill("axe", 410);
        set_skill("literate", 500);
        set_skill("wangxiang-fufa", 450);
        set_skill("shuiyue", 430);
        set_skill("wangran-xinfa", 440);
        set_skill("cxwx-quan", 330);
    
        map_skill("force", "wangran-xinfa");
        map_skill("axe", "wangxiang-fufa");
        map_skill("dodge", "shuiyue");
        map_skill("unarmed", "cxwx-quan");
        map_skill("parry", "wangxiang-fufa");
        map_skill("dodge", "shuiyue");
               
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "axe.wang" :),
        }) );


        setup();
        carry_object("/d/cxwxm/obj/axe.c")->wield();
        carry_object("/d/cxwxm/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        if (!ob->query("xiaojin")) {
                command("say ����ȥ����ʦ�ܰɣ�");
                return;
}
        if ((int)ob->query_skill("wangran-xinfa", 1) < 100) {
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
 
        if (ob->query_int() < 50) {
                command("say �����书ȫƾ�������롣");
                command("say Ҫ���޵���߾��磬������Ի�����");
                command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
        }
   if ((string)ob->query("gender")=="����")
   {
                message_vision("������ϸ��������Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
                ob->set("chuhuan",1);
                       return;}
   else
      {
                message_vision("�Բ�����ֻ����ͽ��\n",ob);
       return;}
        

}


// long.c ���꽿�
// marry 99.8

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("���꽿", ({ "long yujiao","long","jiao" }));
        set("nickname", MAG "Ʈ��Ů" NOR);
        create_family("����������", 3,"����");
        set("jihao",1);
        set("long","�����ǳ��������ŵ�Сʦ�á�Ʈ��Ů�����꽿��");
        set("gender", "Ů��");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 30);
        set("dex", 30);
        
        set("max_qi", 5000);
        set("max_jing", 300);
        set("neili", 20000);
        set("max_neili", 20000);
        set("jiali", 100);
        set("combat_exp", 10000000);
        set("score", 100000);

        set_skill("force", 240);
        set_skill("dodge", 220);
        set_skill("unarmed",240);
        set_skill("parry", 230);
        set_skill("whip", 250);
        set_skill("literate", 300);
        set_skill("chixin-bianfa", 250);
        set_skill("shuiyue", 290);
        set_skill("wangran-xinfa", 300);
        set_skill("cxwx-quan", 200);
    
        map_skill("force", "wangran-xinfa");
        map_skill("whip", "chixin-bianfa");
        map_skill("dodge", "shuiyue");
        map_skill("unarmed", "cxwx-quan");
        map_skill("parry", "chixin-bianfa");
        map_skill("dodge", "shuiyue");
               
        set("chat_chance_combat", 60);
        setup();
        carry_object("/d/cxwxm/obj/whip.c")->wield();
        carry_object("/d/cxwxm/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        int n;
        n = ob->query("combat_exp");
        if ((int)ob->query("shen") < 0) {
                command("say ��������޳�֮ͽ������ɣ�");
                command("say �����ְ��࣬" + RANK_D->query_respect(ob) +
                        "����ɣ�");
                return;
        }
/*
        if ((!ob->query("lunhui"))&&(n > 500000))
       {        command("say �Բ��𣡱��Ų��ս������");
                return;
        }
         if ((ob->query("lunhui"))&&(n > 10000000))
       {        command("say �Բ��𣡱��Ų��ս������");
                return;
        }
*/
       if ((string)ob->query("family/family_name",1)) 
       {
                command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α����������أ�");
                return;
        }
        if ((int)ob->query("per") < 30) {
                command("say �����书�Ǿ�����ò����ϰ�ã�");
                command("say �㻹��ȥ���ݺ�������!");
                return;
        }
 
        if (ob->query_int() < 25) {
                command("say �����书ȫƾ�������롣");
                command("say Ҫ���޵���߾��磬������Ի�����");
                command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
        }
   if ((string)ob->query("gender")=="Ů��")
   {
                message_vision("���꽿��ϸ��������Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
                 ob->set("yujiao",1);
                       return;}
   else
      {
                message_vision("�Բ�����ֻ��Ůͽ��\n",ob);
       return;}
        

}


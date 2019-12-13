#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
        set_name("��Са", ({ "yang xiaoxie", "yang"}));
        set("long", "������ͨ�԰����,Са��-��Са\n");
        set("gender", "����");
        set("age", 19); 
         set("nickname", HIG "ͨ��С����" NOR);
          set("shen",0);
        set("attitude", "peaceful");

        set("str", 65);
        set("int", 65);
        set("con", 65);
        set("dex", 65);
        set("kar", 65);

        set("qi", 40000);
        set("max_qi", 40000);
          set("neili", 8000);
         set("max_jing", 8000);
          set("neili", 9000);
          set("max_neili", 9000);
		set("shen", 50000);
        set("jiali", 1000);

        set("combat_exp", 500000000);
        set("score", 10000);
        set_skill("force", 1500);
        set_skill("dodge", 1500);
        set_skill("parry", 1500);
        set_skill("sword",1500);
        set_skill("unarmed",1500);

        set_skill("dabei-zhang",1500);
        set_skill("damo-force",1500);
        set_skill("guxing-sword",1500); 
          set_skill("literate",1500);
        set_skill("langzi-sword",1500);
        set_skill("piaomiao-shenfa",1500);

        map_skill("unarmed", "dabei-zhang");
        map_skill("force", "damo-force");
        map_skill("dodge", "piaomiao-shenfa");
        map_skill("parry", "dabei-zhang");
        map_skill("sword", "langzi-sword");

        prepare_skill("sword","langzi-sword");
        create_family("ͨ�԰�",1,"����");
        setup();
    carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}

void attempt_apprentice(object ob)
{

                  if ((string)ob->query("gender") == "����") {
                                 command("say ��λ������Ҫ����Ц�ˡ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���ǿ�ȥ�ź���ϰɣ�");
                return;
                  } 
        if ((int)ob->query_skill("damo-force", 1) < 1000) {
                command("say ��Ĵ�Ħ�񹦻�ѧ�Ĳ�������");
                return;
                  } 
        if ((int)ob->query_skill("fanyun-force", 1) < 1000) {
                command("say ��ķ����񹦻�ѧ�Ĳ�������");
                return;
                  } 
         message("vision",HIM"��Ӣ�۴��š�"NOR+":"+HIR" ��˵"HIW+ob->short()+NOR HIB"����ͨ�԰������Са����!\n"NOR,users());
     command("recruit " + ob->query("id"));
               return;
}

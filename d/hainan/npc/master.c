#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int HAVE_WEAPON=1;

int give_weapon();


void create()
{
        set_name(HIY"��������"NOR,({"fan yin", "shenni","fan", "nigu","master"}));
       set("long",
"������������,�ǵ�����������֮һ,��˵�����书�Ѿ����������֮�ĵز�.\n");
       set("title", YEL"����������"NOR);
       set("gender", "Ů��");
       set("age", 96);
       set("attitude", "peaceful");
       set("class","nigu");
       set("rank_info/respect", "����");
       set("per", 30);
        set("int", 30);
        set("inquiry", ([
                        "����" : (: give_weapon :),
                    "����":(:give_weapon:),
                                    "����":(:give_weapon:),

                ]) );   

       set("max_qi", 300000);
       set("max_jing", 300000);
        set("max_jingli", 3000);
       set("neili", 300000);
        set("max_neili", 3000);
       set("force_factor", 60);
       set("combat_exp", 580000000);

       set_skill("literate", 2200);
       set_skill("unarmed", 1200);
       set_skill("dodge", 1200);
       set_skill("force", 1200);
       set_skill("parry", 1200);
       set_skill("sword", 1200);
       set_skill("feixian-jian", 1200);
        set_skill("bitao-shengong", 1200);
        set_skill("baihua-zhang", 1200);
        set_skill("qiongya-bufa", 1200);
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "bitao-shengong");
        map_skill("sword", "feixian-jian");
        map_skill("parry", "feixian-jian");
        map_skill("dodge", "qiongya-bufa");

create_family("������", 3, "����");
setup();

        carry_object("/d/hainan/obj/bai_cloth")->wear();
        carry_object("/d/hainan/obj/yuruyi")->wield();
        add_money("gold.c",10);
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Ů��")){
           command("shake");
           command("say ���ǰ�����ֻ��Ůͽ����λ" +
RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
           return;}
if ( (int)ob->query("dex")<20 && (int)ob->query("kar") < 25)  {
          command("shake");
        command("say ���ҿ���λ" +
RANK_D->query_respect(ob) + "�����ʲ��ʺ�ѧ����һ���书.\n");
        return;
}

        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ���������Ǻ���һ�ɷ�����\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "nigu");
}
int give_weapon()
{  
  object me;

  me=this_player();
if ((me->query("family/master_id")=="zhongling")&&(me->query("family/family_name")=="������"))
 {
  if( me->over_encumbranced() ) return notify_fail("���Ѿ����ɹ����ˣ�\n");

  if(HAVE_WEAPON==0)
    command("say �������ˣ��ⶫ���Ѿ�����ȡ���ˡ�");  
  else  
  {
  clone_object("/d/hainan/obj/hanyue.c")->move(me);

    command("say ������СѾͷ���Ǻ���,������������ȥ�ɡ�");  
    message_vision("���������$nһ�Ѻ���ն��\n",this_object(),me);   
    
    HAVE_WEAPON=0;   
  }

  return 1;
 }
else
 command("say ����������ʲô�������ѽ,�������ЩСѾͷ��˵!\n");
return 1;
}


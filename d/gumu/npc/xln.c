//xln.c С��Ů
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_suo();
string ask_zhen();
 
void create()
{
        set_name("С��Ů", ({ "xiao longnv", "xiao", "longnv" }));
        set("title","��Ĺ����");
        set("nickname",HIC"��Ů����"NOR);
        set("long", "�������쳣����Ҳ���ǳ��ӹ�Ĺ֮�ʣ���ɫ�԰ס�\n");
        set("gender", "Ů��");
        set("age", 39);
//          set("attitude", "friendly");	
        set("per", 40);
        set("str", 24);
        set("dex", 23);
        set("con", 20);
        set("int", 24);
        set("shen", 20000);	
		set("jiali", 13000);
        set("max_qi", 2500000);	
        set("max_jing", 1060000);
        set("neili", 3050000);    	
        set("max_neili", 750000);	
		set("combat_exp", 24000000);	
		
		set("xyzx_sys/level", 1500);
        set_skill("parry", 2900);
		set_skill("force", 2900);	
        set_skill("dodge", 2900);
		set_skill("sword", 2900);	
        set_skill("throwing", 2900);
        set_skill("whip", 2900);
		set_skill("meinv-quanfa", 1900);	
		set_skill("unarmed", 2900);	
        set_skill("yunv-shenfa", 1900);
        set_skill("yinsuo-jinling", 1900); 
        set_skill("literate", 2900);         
		set_skill("yunv-jianfa", 1900);	
		set_skill("quanzhen-jianfa", 1900);  	
		set_skill("yunv-xinjing", 1900);	
		set_skill("qufeng",1300);
        map_skill("force", "yunv-xinjing");
        map_skill("dodge", "yunv-shenfa");
        map_skill("unarmed", "meinv-quanfa");
        map_skill("sword", "yunv-jianfa");
        map_skill("whip", "yinsuo-jinling");
        //prepare_skill("unarmed", "meinv-quanfa");

        create_family("��Ĺ��",3,"Ů����");
        
        
        set("inquiry", ([
            "���" : "�������ҷ������֪�����ܰ��ң���һֱ���������������ơ�", 
          "��Ī��" : "������ʦ�㣬�������Ѿ�����ȥ�����Ż��ˡ�",            "Կ��" : "��....���ҿɼǲ�����������Ƿ��ڹ�Ĺ�����˰ɡ�",
            "����" : (: ask_suo :),
          "�����" : (: ask_zhen :),
        ])); 
         set("zhen_count", 2);
        setup();

carry_object("/clone/npc/obj/golden_sword")->wield();           	
         carry_object("/d/gumu/obj/yinsuo")->wield();
         carry_object("/d/gumu/obj/buxue1")->wear();
        carry_object("/d/gumu/obj/qun1")->wear(); 
}

void attempt_apprentice(object ob)
{
     mapping fam = ob->query("family");
if (!fam || fam["family_name"] != "��Ĺ��" || fam["generation"]!=5){
                command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                return;
                }       
      if((int)ob->query_skill("yunv-xinjing", 1) < 120) {
                command("say �ҹ�Ĺ�书�ڹ��ǻ�����"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
                return;
                }  
      if((int)ob->query_skill("sword", 1) < 100) {
                command("say �㽣����ô��ҽ̵��㲻һ��ѧ�ûᡣ"); 
                command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                return;
                }
      if(ob->query_int() < 32) {
                command("say �ҵ��书��Ҫ���ߵ����Բ���ѧ�ᡣ");
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
                command("say ��λ"+RANK_D->query_respect(ob)+"�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
                }
      if(ob->query("gender") != "Ů��") {
                command("say �ҿ�ֻ��Ůͽ����ȥ���ҷ�����԰ɡ�");
                return;
                }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("recruit " + ob->query("id"));
        ob->set("title","��Ĺ��������´���");
        ob->set("class","sworder");
}

string ask_suo()
{
       object ob = this_player();
       mapping fam = ob->query("family");
       if (!fam || fam["family_name"] != "��Ĺ��" || ob->query("family/master_name") != "С��Ů")
        return RANK_D->query_respect(ob)+"�����Ѿ�����δ�������ˣ�Ҳ��֪�����ںδ��ˡ�";
       if (ob->query_skill("yinsuo-jinling", 1) < 100)
        return "��λ"+ RANK_D->query_respect(ob) +"����������쳣�����Ƿ�Ӧ�ð��书����Щ��";
       ob->set_temp("marks/����", 1);
       command("nod " + ob->query("id"));
       return "���������ͷ��ڴ����У����Ը����Ұɡ�";       
} 

string ask_zhen()
{
                  mapping fam;
                  object ob;

                  if (!(fam = this_player()->query("family"))
                 || fam["family_name"] != "��Ĺ��")
                                         return RANK_D->query_respect(this_player()) +
                                         "�뱾��������������֪�˻��Ӻ�̸��";
                  if (query("zhen_count") < 1)
                                         return "���Ѿ���������Ѹ�����ȥ�����Ż����ˣ���ú��������Ժ��л�����ȥ�ɡ�";
                  add("zhen_count", -1);
                  ob = new("/d/gumu/obj/yfzhen.c");
                  ob->move(this_player());
                  return "�������ԸΪʦ�������Ż���������ƽʱһ�����࣬��ö����������ȥ�ɡ�";
}


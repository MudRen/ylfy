void attempt_apprentice(object ob)
{
         object me,obb;
	mapping my_fam, ob_fam;
	me = this_object();
	my_fam = ob->query("family");
	ob_fam = me->query("family");
        	command("say �ðɣ��Ҿ��������ˡ�");
           command("say ���Ѫ���Ǳ��ɵ������߽����ı�־��ǧ���Ū���ˡ�");
         obb=new("/d/xuehepai/obj/cloth1");
         obb->move(ob);
       ob->set("cloth","/d/xuehepai/obj/cloth1");
		command("recruit " + ob->query("id"));
		return ;
}



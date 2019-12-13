#include <liebiao.h>

void create() 
{
	seteuid( ROOT_UID );
	write("simul_efun �ɹ�����.\n");
}

#include "/adm/simul_efun/atoi.c"
#include "/adm/simul_efun/chinese.c"
#include "/adm/simul_efun/gender.c"
#include "/adm/simul_efun/object.c"
#include "/adm/simul_efun/path.c"
#include "/adm/simul_efun/wizard.c"
// This must be after gender.c
#include "/adm/simul_efun/message.c"
#include "/adm/simul_efun/file.c"
#include "/adm/simul_efun/player.c"
#include "/adm/simul_efun/item.c"
// This is the utilitis
#include "/adm/simul_efun/util.c"
#include "/adm/simul_efun/config.c"

varargs object snoop(object who, object target) 
{
	if(!target)
		return efun::snoop(who);
	
	if(!wizardp(who))
		return 0;
	
	log_file("snoop", who->name() + " snoops " + target->name() + " at " + ctime(time()) );
	return efun::snoop(who, target);
}

void shutdown(int etc)
{
	if( base_name(previous_object()) != NATURE_D && base_name(previous_object()) != "/adm/daemons/automap" )
		return 0;
	else
		efun::shutdown(etc);
}

void destruct(object ob)
{
    string err, name;
	object env, *temp;
	int i;

    if ( objectp(ob) )
    {
        if ( previous_object() )
            err = catch(ob->remove( geteuid(previous_object()) ));
        else
            err = catch(ob->remove(0));
        
		if ( err )
        {
            if ( userp(ob) && geteuid(previous_object()) != ROOT_UID )
               return;
        }

		if ( clonep(ob) && objectp(env = environment(ob)) )
		{
			//Tomud�б�ɾ��
			//------------------------------------------------------
			//���ˣ�ֻ����Ŀǰ�Ŀɻ������
			if(interactive(env)) 
			{
				if(!env->query("xieyi/zmud"))
				{
					//ɾ����Ʒ������б�ͼ��
					tell_object(env,REM1(ob));
				}
			}
			else if(!env->is_character())
			{
				//ͬ�����µ��������
				temp=all_inventory(env);
				for(i=0;i<sizeof(temp);i++)
				{
					if (temp[i] == ob)
						continue;
					if(!temp[i]->query("xieyi/zmud"))
					{
						if (interactive(temp[i]))
							tell_object(temp[i],REM0(ob));
					}
				}
			}
		/*
	���destruct�����������Я���������Ӹ�����������BUG 
	����׷ɱNPC����Ҽ�ʬ���ȥ�����ʱʬ���������δ��������Я�������������´����˸����ۼ�BUG��ʧ
*/			
			if (ob->query_encumbrance() > 0)
				env->add_encumbrance( -ob->query_encumbrance());
			
			if (ob->is_character())//�д���δ����die()����������������ʱ��Ҫ������
				all_inventory(environment(ob))->remove_killer(ob);//������
		}
		
		//����˳���Ϸʱ���������������ҵ�who�б������ҵ�ͼ��
		if(playerp(ob))
		{
			temp=users();
			for(i=0;i<sizeof(temp);i++)
			{
				if(!temp[i]->query("xieyi/zmud"))
				{
					tell_object(temp[i],REM2(ob));
				}
			}

			auto_save_item(ob);

			// ������
			if ( stringp(name = ob->query_temp("xyzx_team/name")) )
				TEAMD->del_team_member(ob);
			/*if ( (ob->query("vrm_in_busy") > time() && !ob->query_temp("no_end_save")) 
				|| objectp(environment(ob)) )*/
			if ( !ob->query_temp("no_end_save") 
				&& objectp(environment(ob)) 
				&& ob->query_temp("save_end_time") != time() )
				ob->save();

			//if ( in_input(ob) ) remove_input_to(ob);
		}

        efun::destruct(ob);
    }
}
//void replace_program(string arg) { return; }

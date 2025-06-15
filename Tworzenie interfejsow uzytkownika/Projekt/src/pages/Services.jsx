import { motion } from 'framer-motion';

export default function Services() {
    const services = [
        {
            icon: '📦',
            title: 'Zarządzanie magazynem',
            desc: 'Dodawaj, edytuj i usuwaj części oraz kontroluj ich stan w czasie rzeczywistym.',
        },
        {
            icon: '🔔',
            title: 'Powiadomienia o brakach',
            desc: 'Otrzymuj alerty o niskim stanie magazynowym i minimalnych progach zapasów.',
        },
        {
            icon: '📊',
            title: 'Raporty i analizy',
            desc: 'Generuj raporty zużycia i analizuj dane, aby lepiej zarządzać zaopatrzeniem.',
        },
        {
            icon: '🔗',
            title: 'Integracje z API',
            desc: 'Łącz się z systemami zewnętrznymi – ERP, fakturowanie, zamówienia online.',
        },
        {
            icon: '👥',
            title: 'Zarządzanie użytkownikami',
            desc: 'Twórz konta pracowników, nadawaj role i monitoruj aktywność.',
        },
        {
            icon: '🔒',
            title: 'Bezpieczeństwo danych',
            desc: 'Kopie zapasowe, szyfrowanie, autoryzacja – Twoje dane są zawsze chronione.',
        },
    ];

    return (
        <motion.div
            className="max-w-6xl mx-auto px-6 py-16 bg-gray-50 dark:bg-gray-900 text-gray-900 dark:text-gray-100"
            initial={{ opacity: 0, y: 10 }}
            animate={{ opacity: 1, y: 0 }}
            exit={{ opacity: 0, y: -10 }}
            transition={{ duration: 0.4 }}
        >
            <motion.h1
                className="text-4xl font-bold mb-8 text-center"
                initial={{ opacity: 0, y: 20 }}
                animate={{ opacity: 1, y: 0 }}
                transition={{ delay: 0.2 }}
            >
                Nasze usługi
            </motion.h1>

            <motion.p
                className="text-lg mb-12 text-center max-w-3xl mx-auto text-gray-700 dark:text-gray-300"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.4 }}
            >
                Nasz system magazynowy oferuje szeroki wachlarz funkcji wspierających codzienną pracę
                mechaników, logistyków oraz zarządców części samochodowych.
            </motion.p>

            <motion.div
                className="grid sm:grid-cols-2 lg:grid-cols-3 gap-8"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.6 }}
            >
                {services.map((item) => (
                    <motion.div
                        key={item.title}
                        className="bg-white dark:bg-gray-800 shadow-lg hover:shadow-2xl dark:shadow-gray-700 dark:hover:shadow-gray-600 rounded-xl p-6 transition-all duration-300 transform"
                        whileHover={{ scale: 1.03 }}
                        transition={{ type: 'spring', stiffness: 300 }}
                    >
                        <div className="text-5xl mb-4">{item.icon}</div>
                        <h2 className="text-lg font-bold mb-2">{item.title}</h2>
                        <p className="text-gray-600 dark:text-gray-300 text-sm">{item.desc}</p>
                    </motion.div>
                ))}
            </motion.div>
        </motion.div>
    );
}

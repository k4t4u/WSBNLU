import { motion } from 'framer-motion';

export default function Blog() {
    const posts = [
        {
            title: 'Jak efektywnie zarządzać magazynem części?',
            date: '2025-05-10',
            excerpt: 'Dowiedz się, jak zoptymalizować procesy magazynowe i uniknąć błędów w zarządzaniu zapasami.',
        },
        {
            title: 'Nowa funkcja: raporty stanów magazynowych',
            date: '2025-04-25',
            excerpt: 'Wprowadziliśmy możliwość generowania raportów PDF z aktualnymi stanami i historią części.',
        },
        {
            title: 'Części zamienne – najczęstsze błędy przy zamówieniach',
            date: '2025-03-18',
            excerpt: 'Sprawdź, jak uniknąć pomyłek przy dobieraniu części i jakie dane warto weryfikować.',
        },
        {
            title: 'Co nowego w wersji 1.5? Zobacz changelog!',
            date: '2025-02-02',
            excerpt: 'Wersja 1.5 to lepsza wydajność, nowe alerty oraz integracje z zewnętrznymi bazami danych.',
        },
    ];

    return (
        <div className="max-w-6xl mx-auto px-6 py-16 bg-gray-50 dark:bg-gray-900 text-gray-900 dark:text-gray-100">
            <motion.h1
                initial={{ opacity: 0, y: -20 }}
                animate={{ opacity: 1, y: 0 }}
                transition={{ duration: 0.5 }}
                className="text-4xl font-bold mb-8 text-center"
            >
                Blog
            </motion.h1>

            <motion.p
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ duration: 0.5, delay: 0.2 }}
                className="text-lg mb-12 text-center max-w-3xl mx-auto text-gray-700 dark:text-gray-300"
            >
                Nowości, porady i aktualizacje dotyczące zarządzania częściami samochodowymi.
                Bądź na bieżąco z naszym systemem!
            </motion.p>

            <div className="grid md:grid-cols-2 gap-8">
                {posts.map((post, index) => (
                    <motion.article
                        key={post.title}
                        initial={{ opacity: 0, y: 10 }}
                        animate={{ opacity: 1, y: 0 }}
                        transition={{ duration: 0.4, delay: 0.3 + index * 0.1 }}
                        className="bg-white dark:bg-gray-800 border-l-4 border-blue-500 rounded-lg p-6 shadow hover:shadow-xl transition-all duration-300"
                    >
                        <p className="text-sm text-blue-600 font-semibold mb-1">
                            {new Date(post.date).toLocaleDateString()}
                        </p>
                        <h2 className="text-xl font-bold mb-2 text-gray-800 dark:text-gray-100">
                            {post.title}
                        </h2>
                        <p className="text-gray-600 dark:text-gray-300 text-sm mb-4">
                            {post.excerpt}
                        </p>
                        <button className="text-blue-600 hover:underline text-sm font-medium">
                            Czytaj więcej →
                        </button>
                    </motion.article>
                ))}
            </div>
        </div>
    );
}
